// guoshi.c 万年无名果

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( "坏掉的"YEL"无花果"NOR, ({"bad wuhua guo", "bad guo"}));
	set_weight(120);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "一颗已经坏掉了的无花果。\n");
		set("value", 0);
		set("no_sell", 1);
	}
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	message_vision(HIR "$N捏起一颗坏掉的无花果送进嘴里吞下，“哇”的一声又吐了出来。\n" NOR, this_player());
	destruct(this_object());
	return 1;
}

