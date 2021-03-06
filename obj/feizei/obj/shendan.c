// shendan.c 千年参心丹
// stone 20020415
//add force +5

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//                set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
//		set("no_give","这么珍贵的药，哪能随便给人？\n");
		set("no_drop","这么稀世珍宝千年参心丹，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"参心丹" NOR, ({"shen dan","dan","shenxin dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", YEL"一颗土黄色的丹药，散发出股股参香味。据说采自蓬莱仙岛
的千年参王，太上老君取其精华，在八卦药炉中慢慢熬练了
七七四十九天才制成，凡人服着可延年益寿。\n"NOR);
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

	me->add_maximum_force(5);
//	me->add_maximum_mana(4);

	message_vision("$N吃下一颗"+YEL"千年参心丹"NOR"，不觉满口香洌，精神抖擞。\n",me);
        tell_object(me, "你只觉一股热气直透丹田......\n" NOR);
	destruct(this_object());
	return 1;
}

