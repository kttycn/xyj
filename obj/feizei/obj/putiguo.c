// putiguo.c 菩提果
// stone 20020415
//add force +5-6
//add mana +5-6
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//              set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
//		set("no_give","这么珍贵的药，哪能随便给人？\n");
		set("no_drop","这可是难得一见的菩提果，扔了未免太可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(WHT"菩提果"NOR, ({"puti guo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗晶莹如玉的菩提果，采自灵山圣地，珍稀无比，
乃万年菩提树之实，乃凡人梦寐以求的珍物。\n");
		set("value", 500000);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	int force_add,mana_add;
	force_add = 3+random(3);
	mana_add = 3+random(3);

	if (!id(arg))
		return notify_fail("你要吃什么？\n");

	me->set("food", (int)me->max_food_capacity());

	me->add_maximum_force(force_add);
	me->add_maximum_mana(mana_add);

	message_vision("$N把"+WHT"菩提果"NOR"放入口中，轻轻一咬，但觉满口清香，饥渴全消，连忙带皮吞下。\n",me);
	tell_object(me, "你只觉一股热气直透四肢百髓......\n" NOR);
  
	destruct(this_object());
	return 1;
}

