// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("乌刺诺斯", ({"uranus", "bao ping"}));
	set("long", "传说中的天空之神，守护着宝瓶座.\n");
	set("gender","男性");
	set("title", BLU"【天空之神】"NOR);
	set("age",37);
	set("con",55);
	set("per",30);
	set("str",73);
	set("int",64);

	set("max_force", 5700);
	set("force", 11400);
	set("max_mana",5700);
	set("mana",11400);
	set("mana_factor",285);
	set("force_factor", 285);
	set("max_kee", 12500);
	set("max_gin", 12500);
	set("max_sen", 12500);
	set("combat_exp",5487200);
	set("daoxing",5487200);

	set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg", ({
		"乌拉诺斯说道：不知何时能再见到雅典娜！\n"   
	}));

	set_skill("dodge", 381);
	set_skill("force", 381);
	set_skill("parry", 381);
	set_skill("unarmed", 381);
	set_skill("sword", 381);
	set_skill("westsword",381);
	set_skill("boxing",381);
	set_skill("balei",381);
	set_skill("spells",381);
	set_skill("baoping", 381);
	map_skill("parry","westsword");
	map_skill("sword","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","baoping");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/bp_cloth")->wear();
	carry_object("/d/obj/weapon/sword/westsword")->wield();
}

void init()
{
	add_action("do_none","perform");
	add_action("do_none","cast");
	add_action("do_none","ji");
}
int do_none()
{
	object me = this_object();
	message_vision("$N冷笑一声：我乃"BLU"【天空之神】"NOR"，你想耍什么花样？\n",me);
	return 1;
} 
void check()
{
	object ob=this_object();
	object ghost;
	object me=query_temp("my_killer");

	if( ! me ) return ;
	if(! present(me,environment()) )
	{
		remove_call_out("check");
		return;
	}			       

	switch(random(6))
	{	
		case 0:
		{
			message_vision(HIY"$N高举宝瓶，一真飓风自$n的脚下升起！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIY"$N根本就控制不住自己，随风升起，然后又重重的摔了下来。！\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIW"$N真气下沉，勉强抵御住$n的飓风。\n"NOR,me,ob);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N突然冲天而去，然后又如闪电般向$n冲了下来！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N居然被$n按到地下达半尺之深,$N急忙从地下转了出来！\n"NOR,me,ob);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
				ob->start_busy(2);
			}
			else
			{
				message_vision(HIG"$N就地一滚，$n一头栽到地下。\n"NOR,me,ob);
				ob->start_busy(1);
			}
		}
		break;
		case 2:
		{
			message_vision(HIC"$N举起手中宝瓶，宝瓶中喷出无数巨石，直奔$n！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIM"$N被石头砸了个头破血流！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
				me->start_busy(1);
			}
			else
				message_vision(HIG"$N听风辨位，在石头阵中杀出一条血路。\n"NOR,me);
		}
		break;
		case 3:
		{
			message_vision(HIW"$N喊了一声：绝对零度！只见一股寒流直袭$n\n"NOR,ob,me);
			if(random(2)==0)
			{
				message_vision(HIW"$N被寒流击中，冻的肢体麻木，似乎要断了一般！\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
				me->start_busy(3);
			}
			else
				message_vision(HIW"$N不停的运动自己的身体，以保持一点温暖。\n"NOR,me);
		}
		break;
	}
	if( random(7) == 5 )
	powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}
void die()
{
	object ob = query_temp("my_killer");
	if((ob&&ob->query("12gong/mojie")=="done") && (ob&&ob->query("12gong/baoping")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
		"闯过了第十一宫宝瓶座，向黄金战士努力！\n"NOR,users());
		ob->set("12gong/baoping","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"你赢得了十年道行");
	}
	::die();
}
