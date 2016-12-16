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
	set_name(HIR"朱果"NOR, ({"zhu guo", "guo"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", HIY"这是一粒通体朱红色的鲜果。此果生于长白山老林中，几千年才能结实。\n"+
			"相传为一名万年老仙未得灵徒，每日悲伤呕血于此草之上养育而成。\n"NOR);
		set("value", 900000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if ((string)environment(me)->query("short")=="禹王林" )
		return notify_fail("这里这么危险还吃什么东西啊？\n");

	me->add_maximum_force(100);
	message_vision(HIW"$N喜极若狂，一口吞下了朱果。骨骼“喀喇”作响。\n" NOR, me,);
	me->unconcious();
	destruct(this_object());
	return 1;
}

