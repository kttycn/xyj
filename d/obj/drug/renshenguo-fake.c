#include <ansi.h>

inherit ITEM;
int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
		set("drug_type", "补品");
	}

//	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	if(environment(me)->query("alternative_die"))
		return notify_fail("你不能在这儿吃"+name()+"。\n");

	message_vision(HIW "$N把人参果往嘴里一塞，却什么反映也没有，看来是个假人参果。\n" NOR, me);
	return 1;
}
