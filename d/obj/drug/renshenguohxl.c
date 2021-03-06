#include <ansi.h>

inherit ITEM;

int do_eat(string);
void disappear(object me);

void create()
{
	set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
		set("value", 0);
		set("no_give",1);
		set("no_drop",1);
		set("no_put",1);
		set("no_get",1);
		set("no_sell,1);//石头加
		set("drug_type", "补品");
	}

	set("is_monitored",1);
	setup();
}

void init()
{
	object me=this_object();
	add_action("do_eat","eat");
	if (!me->query("start_time"))
	{
		me->set("start_time",1);
		return ;
	}
	remove_call_out("disappear");
	call_out("disappear",900,me);
	return ;
}                  


int do_eat(string arg)
{
	int howmany;
	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	if(environment(me)->query("alternative_die"))
		return notify_fail("你不能在这儿吃"+name()+"。\n");

	message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n" NOR, me);  
	me->unconcious();
	me->set("food", (int)me->max_food_capacity());

	if( howmany <= 100 ) me->add_maximum_force(80);
	if( howmany <= 100 ) me->add_maximum_mana(80);

	howmany = (int)me->query("rsg_eaten");
	me->set("rsg_eaten", howmany+1);

//for live forever...
	if( me->query("rsg_eaten") >= 36 && !me->query("life/live_forever_announced") )
	{
	    me->set("life/live_forever_announced", 1);
    	me->set("life/live_forever", 1);
		me->add("score", 100);
		me->announce_live_forever( me->query("name")+"坚持不懈地吃人参果，终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
	}

	destruct(this_object());
	return 1;
}

void disappear(object me)
{
	if (!me) return ;
	message_vision("$N突然钻进地里不见了.:-(\n",me);
	destruct (me);
}
