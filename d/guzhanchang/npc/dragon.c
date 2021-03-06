#include <ansi.h>
inherit NPC;
int big_blowing();
void create()
{
	set_name("千年赤蛟", ({"chi jiao","jiao"}));
	set("long", "这是一条全身赤红的赤蛟。只见头如麦
斗，形似蛇头，眼似铜铃，头正中却生
了一只两尺多长，往外弯伸的独角，满
身麟甲，口中利齿如刀，但红信却是又
细又长。    
\n");
	set("race", "野兽");
	set("age", 2943);
	set("attitude", "aggressive");
	set("per", 9);
	set("max_kee", 15000);
	set("max_gin", 6000);
	set("max_sen", 15000);
	set("max_mana", 6000);
	set("max_force", 5500);
	set("force", 12000);
	set("mana", 12000);
	set("force_factor", 140);
	set("mana_factor", 150);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("chat_chance_combat", random(80));
	set("chat_msg_combat", ({
		(: big_blowing :)
	}) );

	set("combat_exp", 2000000+random(2000000));
	set("daoxing", 2000000+random(2000000));
	set_temp("apply/attack", 260+random(400));
	set_temp("apply/damage",200+random(200));
	set_temp("apply/armor", 540+random(500));
	setup();
}
int big_blowing()
{
	remove_call_out("hurting");
	message_vision( HIR "\n\n$N猛然一声大吼，全身散发出熊熊烈焰，霎时周围气温变得炙热无比！\n
\n" NOR,this_object());
	call_out("hurting",random(10)+2);
	return 1;
}
int hurting()
{
	int i;
	int dam;
	object *inv;
	message_vision( HIR "\n\n$N猛吸了一口气，喷出一条火焰，夹着灼人的热气，扑向四周．．\n\n",this_object());
	inv = all_inventory(environment(this_object()));
	for(i=sizeof(inv)-1; i>=0; i--)
		if( living(inv[i]))
			if( inv[i] != this_object())
			{
				dam = random(300)+100 - inv[i]->query_temp("apply/armor_vs_spells");
				if(dam <0) dam = 0;
				inv[i]->receive_wound("kee",dam);
				COMBAT_D->report_status(inv[i],1);
			}
	return 1;
}


void die()
{
	int i;
	object me, jiaosword;
	string jiaosword_given;
	jiaosword_given = "/d/guzhanchang/obj/jiaosword";
	if(objectp(me = query_temp("last_damage_from") ))
	{
		if ( (!jiaosword_given->in_mud()) ) 
		{	
			message_vision("$n喝道：“孽障还不现出原形”。\n一阵红光闪过，$N化为一柄赤红色的剑，飞到$n的手中。\n",this_object(),me);
			jiaosword = new("/d/guzhanchang/obj/jiaosword");
			jiaosword->move(me);
			MONITOR_D->report_rumor_object_msg(me, "拿到赤蛟剑了！");
			destruct(this_object());
			return;
		} else { 
		message_vision ("$N"HIY"化做一道红光，消失了......\n"NOR,this_object());
		destruct (this_object());
		return;
			}
	}	
	return;
}

