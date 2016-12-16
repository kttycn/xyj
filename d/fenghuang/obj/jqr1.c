inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>; 
void setup()
{}
void init()
{
	add_action("do_da", "da");
	add_action("do_jia", "jia");
}
void create()
{
	set_name(HIY"������"NOR"һ��", ({ "jiqi ren","ren", }));
	set_weight(1000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "stone");
		set("no_get", "����������᲻�����㻹�Ǳ�����ˡ�\n");
		set("long", "����һ�������õĻ����������(da)(jia)��\n", );
	}
}

int do_da(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (!(arg=="jiqi ren" || arg == "jiqi"))
		return 0;
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("���޷���ս����ר��������\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "�����"
	&& !(int)me->query("xmark/ѧԱ"))
	{
		write("�㲻�Ƿ��սʿ�����ã�\n");
		return 1;
	}
	if (!id(arg)) { 
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	message("vision", me->name() + "��ʼʹ�û����ˡ�\n", environment(me), me);
	if( (int)me->query("kee") < 5 ) {
		write("�����ڹ���ƣ�룬�޷�ר��������\n");
		return 1;
	}
	pxlevel = me->query_skill("unarmed", 1);
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("���ʵս���鲻�㣬�����á�\n");
		return 1;
	}
	if( me->query_skill("unarmed", 1) > 80){
		write("���Ѿ����ܴӻ������������򵽸���Ķ����ˡ�\n");
		return 1;
	}
	me->receive_damage("kee", 30);
	me->improve_skill("unarmed", (int)me->query_skill("unarmed", 1)/2+random(200));
	write("�㿪ʼʹ�û����ˡ�\n");
	return 1;
}
int do_jia(string arg)
{
	object me = this_player();
	object where = environment(me);
	object ob;
	mapping skill;
	int pxlevel; 

	if (!(arg=="jiqi ren" || arg == "jiqi"))
		return 0;
	if (me->is_busy()) {
		write("��������æ���ء�\n");
		return 1;
	}
	if( me->is_fighting() ) {
		write("���޷���ս����ר��������\n");
		return 1;
	}
	if ((string)me->query("family/family_name") != "�����"
	&& !(int)me->query("xmark/ѧԱ"))
	{
		write("�㲻�Ƿ��սʿ�����ã�\n");
		return 1;
	}
	if (!id(arg)) { 
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	message("vision", me->name() + "��ʼʹ�û����ˡ�\n", environment(me), me);
	if( (int)me->query("kee") < 20 ) {
		write("�����ڹ���ƣ�룬�޷�ר��������\n");
		return 1;
	}
	pxlevel = me->query_skill("parry", 1);
	if( (int)me->query("combat_exp") < (int)pxlevel*pxlevel*pxlevel/10 ) {
		write("���ʵս���鲻�㣬�����á�\n");
		return 1;
	}
	if( me->query_skill("parry", 1) > 80){
		write("���Ѿ����ܴӻ������������򵽸���Ķ����ˡ�\n");
		return 1;
	}
	me->receive_damage("kee", 30);
	me->improve_skill("parry", (int)me->query_skill("parry", 1)/2+random(200));
	write("�㿪ʼʹ�û����ˡ�\n");
	return 1;
}

