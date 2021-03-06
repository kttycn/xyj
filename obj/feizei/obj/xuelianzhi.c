// xuelianzhi.c 灵芝
// stone 20020415
//add force +3
//add mana  +3
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//                set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
//		set("no_give","这么珍贵的药，哪能随便给人？\n");
		set("no_drop","这么宝贵的雪莲子，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"雪莲子" NOR, ({"lian zhi","xuelian zhi","lianzhi"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", WHT"一颗晶莹圆润的雪莲子，产自大雪山地脉深处的千年雪莲
所结的果实，十分罕见，幽幽的发出一股泌人心脾的清香。\n"NOR);
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

	me->add_maximum_force(3);
	me->add_maximum_mana(3);

	message_vision("$N剥开莲皮，小心把"+YEL"雪莲子"NOR"纳入口中，立刻感到心平气和，耳聪目明。\n" NOR, me);
        tell_object(me, "只觉一股暧流汇入丹田，聚灵台......\n" NOR);
	destruct(this_object());
	return 1;
}

