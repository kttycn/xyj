inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
	add_action("do_du", "du");
	add_action("do_du", "study");
}
void create()
{
	set_name(HIM"���Ů��"NOR"��", ({ "nvshen xiang","xiang", }));
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "stone");
		set("no_get", "����������᲻�����㻹�Ǳ�����ˡ�\n");
		set("long",
	"����һ������ˮ�����ĵ�ɵķ��Ů����\n"
	"����������������Ů������������ȥ��\n", );
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel, neili_lost, busy;

	if (!(arg=="nvshen xiang" || arg == "xiang"))
	return 0;
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "�����"
	&& !(int)me->query("xmark/ѧԱ"))
	     {
	     write("�㻹���Ͻ��ܣ�Ҫ�������������˴����ˣ�\n");
		return 1;
	}
	if (!id(arg)) { 
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	if( !me->query_skill("literate", 1) ){
		write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
		return 1;
	}
	busy = 1;
	pxlevel = me->query_skill("dodge", 1);
	if(pxlevel > 140) {
		neili_lost = 3;
		busy = 5;
	} else if(pxlevel > 100) {
		neili_lost = 3;
		busy = 3;
	} else if(pxlevel > 50)
		neili_lost = 3;
	else neili_lost = 0;

	if( (int)me->query("force") < neili_lost && pxlevel > 50 ) {
		write("�������������޷�������ô������书��\n");
		return 1;
	}
	if( (int)me->query("sen") < 15 ) {
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
		return 1;
	}
	if( pxlevel > 180){
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}
	message("vision", me->name() + "���Ů�����̬��������İ��\n", environment(me), me);
	me->receive_damage("sen", 15);
	me->set("force",(int)me->query("force")-neili_lost);
	me->start_busy(busy);
	if (me->query("food") >= pxlevel) me->add("food",-pxlevel/10);
	else me->set("food", 0);

	if (me->query("water") >= pxlevel) me->add("water",-pxlevel/10);
	else me->set("water", 0);
	me->improve_skill("dodge", (int)me->query_skill("literate", 1)/2+random(10));
	write("���Ů�����̬��������İ��\n");
	return 1;
}
