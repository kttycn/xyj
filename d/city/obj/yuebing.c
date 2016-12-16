// yuebing 月饼

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("中秋节的月饼", ({"yue bing", "bing"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中秋节给大家的礼物.。\n");
		set("unit", "只");
		set("no_get", 1);
		set("no_give", 1);
	}
		set("is_monitored",1);//石头加
		setup();//石头加
}

void init()
{
	add_action("do_eat","eat");
}
int do_eat()
{
	object me;
	me = this_player();
	if(!me->query("marks/yuebing"))
	{
		message_vision("$N一口把月饼吞下了肚里。\n",me);
		me -> add("combat_exp",5000);
		me -> add("daoxing",5000);
		me -> add("potential",3000);
		me->add_maximum_force(100);
		me->add_maximum_mana(100);
		tell_object(me,HIR"你被奖励了五年道行、五千点武学经验,三千点潜能和一百点内力与法力。\n"NOR);
		me->set("marks/yuebing",1);
	}
	else tell_object(me,"你已经吃过一次月饼了，还想吃？\n");
	destruct(this_object());
	return 1;
}
