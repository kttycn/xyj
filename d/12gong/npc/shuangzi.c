inherit NPC;
#include "star.h"
 
void create()
{
	set_name("赫淮斯托斯", ({"hephaestus", "shuang zi"}));
	set("long", "传说中的火神赫淮斯托斯，守护双子座。\n");
	set("gender","男性");
	set("title", HIR"【火神】"NOR);
	set("age",37);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 3300);
	set("force", 6600);
	set("max_mana",3300);
	set("mana",6600);
	set("mana_factor",156);
	set("force_factor", 165);
	set("max_kee", 3000);
	set("max_gin", 3000);
	set("max_sen", 3000);
	set("combat_exp",1064800);
	set("daoxing",1064800);

	set("chat_chance",20);
	set("chat_msg", ({
		"赫淮斯托斯说道：不知何时能再见到雅典娜！\n"   
	}));

	set_skill("dodge", 221);
	set("attitude", "friendly");
	set_skill("force", 221);
	set_skill("parry", 221);
	set_skill("unarmed", 221);
	set_skill("sword", 221);
	set_skill("westsword",221);
	set_skill("boxing",221);
	set_skill("balei",221);
	set_skill("spells",221);
	set_skill("shuangzi", 221);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","shuangzi");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/sz_cloth")->wear();
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
	message_vision("$N冷笑一声：在我"HIR"【火神】"NOR"面前，还想有什么花样？\n",me);
	return 1;
}

void check()
{
	object ob=this_object();
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
			message_vision(HIG"$N手中令旗一挥，一阵狂风呼啸而起！\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIG"$N被风吹的跪在地上，毫无半点力量！\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(HIC"$N一挥手中令旗，一道闪电劈向$n！\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIC"$N被闪电劈了个正着，直电的头皮发麻！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIC"$N早就看清了闪电的方向，轻轻一闪，躲开了。\n"NOR,me);
		}
		break;
	}
	if( random(8) == 5 )
		powerup();

	remove_call_out("check");
	call_out("check",2+random(3));
}

void die()
{
	object ob = query_temp("my_killer");

	if((ob&&ob->query("12gong/jinniu")=="done") && (ob&&ob->query("12gong/shuangzi")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
		"闯过了第三宫双子座，向黄金战士进军。\n"NOR,users());
		ob->set("12gong/shuangzi","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"你得到了十年道行,是不是觉得比较少哇,嘿嘿,你就认了吧!");
	}
	::die();
}
