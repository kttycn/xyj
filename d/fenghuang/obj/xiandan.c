#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"���"NOR, ({"zhu guo", "guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", HIY"����һ��ͨ�����ɫ���ʹ����˹����ڳ���ɽ�����У���ǧ����ܽ�ʵ��\n"+
			"�ഫΪһ����������δ����ͽ��ÿ�ձ���ŻѪ�ڴ˲�֮���������ɡ�\n"NOR);
		set("value", 900000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");
	if ((string)environment(me)->query("short")=="������" )
		return notify_fail("������ôΣ�ջ���ʲô��������\n");

	me->add_maximum_force(100);
	message_vision(HIW"$Nϲ������һ����������������������������졣\n" NOR, me,);
	me->unconcious();
	destruct(this_object());
	return 1;
}

