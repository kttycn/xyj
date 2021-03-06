#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
		set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
	}
	if(this_player()==environment())
	add_action("do_eat", "eat");
}

void create()
{
	set_name( MAG "月影奇缘大补丹" NOR , ({"da bu dan","dan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "经过巫师们九九八十一天精心炼制的大补丹(dan)，据说吃(eat)了有奇效。\n");
		set("value", 100);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (arg!="dan") return 0;

	seteuid(getuid());
	switch (random(5))
	{
		case 0:
			me->add("combat_exp",50);
			message_vision(HIM "$N拿起一颗月影奇缘大补丹，小心翼翼地吃了进去。
好酷啊！$N的武学经验增加了50点！\n" NOR, me);
			break;
		case 1:
			me->add("daoxing",200);
			message_vision(HIG "$N拿起一颗月影奇缘大补丹，小心翼翼地吃了进去。
好酷啊！$N的道行增加了50天！\n" NOR, me);
			break;
		case 2:
			me->add("potential",50);
			message_vision(HIR "$N拿起一颗月影奇缘大补丹，小心翼翼地吃了进去。
好酷啊！$N的潜能增加了50点！\n" NOR, me);
			break;
		case 3:
			me->add_maximum_force(5);
			message_vision(HIB "$N拿起一颗月影奇缘大补丹，小心翼翼地吃了进去。
好酷啊！$N的内力增加了5点！\n" NOR, me);
			break;
		case 4:
			me->add_maximum_mana(5);
			message_vision(HIW "$N拿起一颗月影奇缘大补丹，小心翼翼地吃了进去。
好酷啊！$N的法力增加了5点！\n" NOR, me);
			break;
	}
	destruct(this_object());
	return 1;
}
