#include <ansi.h>
inherit ITEM;

int do_eat(string);
void destroy();
void init();

void init()
{
	if(this_player()==environment())
		add_action("do_eat", "eat");
}

void create()
{
	set_name(RED"火龙肝"NOR, ({"huolong gan", "gan"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", HIY"这是一粒通体朱红色的火龙肝.\n"NOR);
		set("value", 900000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (!id(arg)) return notify_fail("你要吃什么？\n");
	if ((string)environment(me)->query("short")=="禹王林" )
		return notify_fail("这里这么危险还吃什么东西啊？\n");

	me->set("food", (int)me->max_food_capacity());
	me->add_maximum_mana(50);
	me->add_maximum_force(50);
	message_vision(HIR"$N喜极若狂，一口吞下了火龙肝。骨骼“喀喇”作响。\n" NOR, me,);
	me->unconcious();
	destruct(this_object());
	return 1;
}


