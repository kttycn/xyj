// by happ@YSZZ
inherit NPC;
#include "star.h"
 
void create()
{
	set_name("普洛塞庇娜", ({"proserpina", "tian chen"}));
	set("long", "传说中的立法之神，守护着天秤座.。\n");
	set("gender","女性");
	set("title", MAG"【大女神】"NOR);
	set("age",20);
	set("con",30);
	set("per",30);
	set("str",25);
	set("int",35);

	set("max_force", 4500);
	set("force", 9000);
	set("max_mana",4500);
	set("mana",9000);
	set("mana_factor",225);
	set("force_factor", 225);
	set("max_kee", 7000);
	set("max_gin", 7000);
	set("max_sen", 7000);
	set("combat_exp",2700000);
	set("daoxing",2700000);

	set("chat_chance",20);
	set("chat_msg", ({
		"普洛塞庇娜说道：不知何时能再见到雅典娜！\n"   
	}));
	set("attitude", "friendly");

	set_skill("dodge", 301);
	set_skill("force", 301);
	set_skill("parry", 301);
	set_skill("unarmed", 301);
	set_skill("sword", 301);
	set_skill("westsword",301);
	set_skill("balei",301);
	set_skill("boxing",301);
	set_skill("tianchen", 301);
	map_skill("sword","westsword");
	map_skill("parry","westsword");
	map_skill("unarmed","boxing");
	map_skill("spells","tianchen");
	map_skill("dodge","balei");

	setup();
	carry_object(__DIR__"obj/tc_cloth")->wear();
	carry_object("/d/obj/weapon/staff/chanzhang")->wield();
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
	message_vision("$N冷笑一声：在我"MAG"【大女神】"NOR"面前，还想有什么花样？\n",me);
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
	switch(random(5))
	{	
		case 0:
		{
			message_vision(HIC"$N大喊一声『升龙霸』一条红龙自九天而起，直飞$n！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIC"$N被红龙在空中顶得翻了几十个跟头！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIG"$N身型急转，不知道绕了多少圈才躲过红龙的攻击！\n"NOR,me);
		}
		break;
		case 1:
		{
			message_vision(YEL"$N高喊一声：『亢龙霸』，一条黑龙自溅底而出，尾巴向$n扫去！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(GRN"$N被黑龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,me);
				me->add("eff_kee",-2*query("max_kee")/10);
				me->add("eff_sen",-2*query("max_sen")/10);
			}
			else
				message_vision(HIY"$N用尽全身力气，飞升而起，黑龙的尾巴正从$N的脚底板下扫过！\n"NOR,me);
		} 
		break;
		case 2:
		{
			message_vision(HIR"$N高喊一声：『百龙霸』，无数只绿龙向$n冲过来！\n",ob,me);
			if(random(2)==0)
			{
				message_vision(HIR"$N如一个球一样，被无数只绿龙在空中戏弄着！\n"NOR,me);
				me->add("eff_kee",-3*query("max_kee")/10);
				me->add("eff_sen",-3*query("max_sen")/10);
			}
			else
				message_vision(HIR"$N看准了绿龙之间的空隙，左转右转，才勉强离难！\n"NOR,me,ob);
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

	if((ob&&ob->query("12gong/shinu")=="done") && (ob&&ob->query("12gong/tiancheng")!="done"))
	{
	ob->start_busy(3);
	message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
	"闯过了第七宫：天秤宫!\n"NOR,users());
	ob->set("12gong/tiancheng","done");
	ob->add("12gong/number",1);
	ob->add("daoxing", 10000);
	tell_object(ob,"你赢得了十年道行");

	}
	::die();
}
