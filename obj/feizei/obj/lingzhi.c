// lingzhi.c 灵芝
// stone 20020415
//add mana +5
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
//                set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
//		set("no_give","这么珍贵的药，哪能随便给人？\n");
		set("no_drop","这么宝贵的百年灵芝，扔了多可惜呀！\n");
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}                                    
	add_action("do_eat", "eat");
}

void create()
{
	set_name(YEL"百年灵芝" NOR, ({"lingzhi","ling zhi"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", YEL"赤褐色的一颗灵芝，芝盖上布有环纹,闪着
油亮的光泽，散发出阵阵扑鼻而来的香气。\n"NOR);
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

//	me->add_maximum_force(4);
	me->add_maximum_mana(5);

	message_vision("$N吃下一株"+YEL"百年灵芝"NOR"，顿时感到神采奕奕，飘飘欲仙。\n" NOR, me);
        tell_object(me, "你只觉一股灵气直冲灵台，浑身上下无不舒坦......\n" NOR);
	destruct(this_object());
	return 1;
}

