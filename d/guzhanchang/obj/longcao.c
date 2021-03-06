// /d/guzhanchang/obj/longcao.c 龙涎草
//stone 20020625
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
		set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
		set("no_give","这么珍贵的仙草，哪能随便给人？\n");
		set("no_drop","这么宝贵的仙草，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "龙涎草" NOR, ({"longcao","long cao"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "一株碧绿发亮的嫩草，经蛟龙唾涎灌溉而生，具有固本培元之疗效。\n");
		set("value", 5000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	me->set("food", (int)me->max_food_capacity());

	me->add_maximum_force(10);
	me->add_maximum_mana(10);

	message_vision(RED "$N三下两下咽下一颗"+HIG"龙涎草"+HIG"，立时精满神足，红光满面！ \n" NOR, me);
  
	destruct(this_object());
	return 1;
}

