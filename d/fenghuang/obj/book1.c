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
	set_name(HIM"��"NOR"��", ({ "shen shu","shu", }));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "stone");
	}
}

int do_du(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 
	int neili_lost;

	if (!(arg=="book" || arg == "shu"))
		return 0;
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("���޷���ս����ר�������ж���֪��\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "�����")
	{
		write("�㲻�Ƿ��սʿ�����ܶ���\n");
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
	message("vision", me->name() + "�������ѧ��һЩ������\n", environment(me), me);
	if( (int)me->query("sen") < 5 ) {
		write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
		return 1;
	}
	if( me->query_skill("literate", 1) > 80){
		write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
		return 1;
	}
	me->receive_damage("sen", 5);
	me->set("force",(int)me->query("force")-neili_lost);
	me->improve_skill("literate", (int)me->query_skill("literate", 1)/2+random(100));
	write("�������ѧ��һЩ������\n");
	return 1;
}

