// by night
// fid 修改

#include <ansi.h>
#include <command.h>

inherit ITEM; 

int do_eat(string);
void init();

void init()
{
	if (!wizardp(this_player())) {
		set("no_get","蛋糕掉在地上就不能吃了！\n");
		set("no_give","这是生日蛋糕啊，怎么能随便给人呢？\n");
		set("no_drop","生日蛋糕扔了多可惜呀！\n");
		set("no_sell","这是定做的，卖不掉了。\n");
	}
	add_action("do_eat", "eat"); 
	add_action("do_wish", "wish");}

void create()
{
	set_name( HIY "生日蛋糕" NOR , ({"cake", "dangao"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块高级奶油蛋糕，上面有几个字：\n\n"
HIR"                  祝你生日快乐\n"NOR);
		set("no_beg",1);
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);
		set("drug_type", "补品");
	}
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	object me, ob;
	int vkar,gain;
	me = this_player(); 
	vkar=(int)me->query("kar");
	if (arg!="cake" && arg!="dangao")
		return notify_fail("你想吃什么？\n");

	if ( me->query("fired") )
	{
		if ( me->query("wished") )
		{   
			me->set("food", (int)me->max_food_capacity());
			me->set("water", (int)me->max_water_capacity()); 

			message_vision(HIG "$N三口两口地把蛋糕吃了下去，打了个饱嗝。\n\n" NOR, me);  
			message_vision(HIG "$N的愿望实现啦！\n" NOR, me);  
			me->set("fired",0);
			if ( me->query_temp("marks/exp") ){ 
				gain=vkar * 16;
				me->add("combat_exp",gain); 
				me->set("wished",0);
				me->set_temp("marks/exp",0); 
				destruct(this_object());
				return 1;
			}
			if ( me->query_temp("marks/dx") ){ 
				gain=vkar * 16;
				me->add("daoxing",gain); 
				me->set("wished",0);
				me->set_temp("marks/dx",0); 
				destruct(this_object());
				return 1;
			}
			if ( me->query_temp("marks/pot") ){ 
				gain=vkar * 9;
				me->add("potential",gain);
				me->set("wished",0);
				me->set_temp("marks/pot",0); 
				destruct(this_object());
				return 1;
			}
			if ( me->query_temp("marks/gold") ){
				ob=new("/clone/money/gold");
				ob->set_amount(vkar);  
				ob->move(me);
				me->set("wished",0);
				me->set_temp("marks/gold",0); 
				destruct(this_object());
				return 1;
			} 
			if ( me->query_temp("marks/force") ){ 
				gain=vkar / 3+8;
				me->add_maximum_force(gain);
				me->set("wished",0);
				me->set_temp("marks/force",0); 
				destruct(this_object());
				return 1;
			}
			if ( me->query_temp("marks/mana") ){ 
				gain=vkar / 3+8;
				me->add_maximum_mana(gain);
				me->set("wished",0);
				me->set_temp("marks/mana",0); 
				destruct(this_object());
				return 1;
			}
			return 1;
		} 
		tell_object(me,"吃蛋糕前先许个愿(wish)吧。\n"
"可以许愿要经验(exp)、道行(dx)、潜能(pot)、黄金(gold)或者内力(force)和法力(mana)。\n");
		return 1;
	} 
	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity()); 
	me->add("combat_exp",vkar*10); 
	message_vision(HIG "$N狼吞虎咽地把蛋糕吃了下去，意犹未尽地抹了抹嘴。\n" NOR, me);   
	destruct(this_object());
	return 1;
}
 
int do_wish(string arg) 
{
	object me;
	me = this_player();

	if (arg=="pot") { 
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/pot",1);
		return 1;
	}  
	if (arg=="gold") { 
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/gold",1);
		return 1;
    } 
	if (arg=="force") {
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/force",1);
		return 1;
	} 
	if (arg=="mana") {
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/mana",1);
		return 1;
	} 
	if (arg=="exp") {
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/exp",1);
		return 1;
	} 
	if (arg=="dx") {
		message_vision(HIY "$N闭上眼睛，默默地许了个愿。\n" NOR, me);  
		me->set("wished",1);
		me->set_temp("marks/dx",1);
		return 1;
	} 
	return notify_fail("你想许什么愿？可以许愿要经验(exp)、潜能(pot)、黄金(gold)或者内力(force)。\n"); 
}

void owner_is_killed()
{
	object me = this_player();
	write(HIM"只见一阵烟雾闪过...尸体上什么东西消失了。\n"NOR);
	destruct(this_object());
	return;
}
