#include <ansi.h>
inherit ITEM;
 void create()
{
	set_name(HIG "ҩ" NOR, ({"yao", "yao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
	}

	setup();
}

void init()
{
	add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");
	this_player()->add("sen",40);
	me->add("potential",10)

	message_vision(HIG"$N����һ��ҩ! \n"NOR,me);
	destruct(this_object());
}

