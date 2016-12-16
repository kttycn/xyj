// by happ@YSZZ
 
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("阿佛洛狄忒", ({"aphrodite", "jin niu"}));
	set("long", "传说中的爱与美的女神－阿佛洛狄忒，守护着金牛座\n");
	set("gender","女性");
	set("title", HIM"【美神】"NOR);
	set("age",37);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 3000);
	set("force", 6000);
	set("max_mana",3000);
	set("mana",6000);
	set("mana_factor",150);
	set("force_factor", 150);
	set("max_kee", 2000);
	set("max_gin", 2000);
	set("max_sen", 2000);
	set("combat_exp",800000);
	set("daoxing",800000);

	set("chat_chance",20);
	set("chat_msg", ({
		"阿佛洛狄忒说道：不知何时能再见到雅典娜！\n"   
	}));

	set_skill("dodge", 201);
	set("attitude", "friendly");
	set_skill("force", 201);
	set_skill("parry", 201);
	set_skill("unarmed", 201);
	set_skill("sword", 201);
	set_skill("westsword",201);
	set_skill("boxing",201);
	set_skill("balei",201);
	set_skill("spells",201);
	set_skill("jinniu", 201);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","jinniu");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/jn_cloth")->wear();
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
	message_vision("$N冷笑一声：我乃"HIM"【美神】"NOR"，你想耍什么花样？\n",me);
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
			message_vision(YEL"$N挥挥衣袖，黄土向$n卷卷而来！\n",ob,me);
			if(random(3)==0)
			{
				message_vision(YEL"$N被飞来的黄土淹没了双眼！\n"NOR,me);
				me->add("eff_kee",-query("max_kee")/10);
				me->add("eff_sen",-query("max_sen")/10);
			}
			else
				message_vision(YEL"$N也鼓起嘴巴，把飞来的黄土纷纷吹落在地！\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(YEL"$N念念有词，一只斗牛向$n冲来！\n",ob,me);
			if(random(3)==0)
			{
				message_vision(YEL"$N被斗牛的尖角转了个大窟窿！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
		}
		break;
		case 2:
		{
			message_vision(HIR"$N向$n射出了爱情之箭。\n",ob,me);
			if(random(3)==0)
			{
				message_vision(HIR"$N不但不躲避，反而迎了上去！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIR"$N看准方向，躲开了$n的爱情之箭！\n"NOR,me,ob);
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
	if((ob&&ob->query("12gong/baiyang")=="done") && (ob&&ob->query("12gong/jinniu")!="done"))
	{
		ob->start_busy(3);
		message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
		"闯过了第二宫：金牛宫!\n"NOR,users());
		ob->set("12gong/jinniu","done");
		ob->add("12gong/number",1);
		ob->add("daoxing", 10000);
		tell_object(ob,"你赢得了十年道行");
	}
	::die();
}
