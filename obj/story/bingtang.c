// lingzhi.c ���Ǻ�«
//����(lywin)2000/4/22

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
	set_name(HIM"���Ǻ�«"NOR, ({"bingtang hulu", "hulu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ��������ı��Ǻ�«����˵��һ�ÿɵ�500��ѧ��200Ǳ�ܡ�\n");
		set("value", 0);
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 500);
	this_player()->add("potential",200);
	message_vision("$N����һ�����Ǻ�«��ֻ�����Լ��ֱ�������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

