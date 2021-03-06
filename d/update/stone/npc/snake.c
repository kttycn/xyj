//snake.c

inherit NPC;
#include <ansi.h>
int fog();

void create()
{
	set_name("千年雪蛇", ({ "xue she", "snake","xueshe" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一条小蛇，长仅半尺，但通体雪白，晶莹剔透，但惟头上有一朱赤冠，在白雪中昂首吐信，嘶嘶作响。\n");
	set("attitude", "aggressive");
	set("kee", 6000);
	set("max_kee", 6000);
	set("sen", 5000);
	set("max_sen", 5000);
	set("max_mana",1500);
	set("max_force",1500);
	set("mana",1500);
	set("force",1500);
	set("str", 90);
	set("cor", 90);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);
/*	set_skill("spells", 250);
  	set_skill("force", 250);
  	set_skill("unarmed", 250);
  	set_skill("puti-zhi", 250);
 	set_skill("parry", 250);
 	set_skill("wuxiangforce", 250);
 	set_skill("dao", 250);
 	set_skill("dodge", 250);
 	set_skill("jindouyun", 250);
 	map_skill("dodge", "jindouyun");
  	map_skill("unarmed", "puti-zhi");
  	map_skill("spells", "dao");
 	map_skill("force", "wuxiangforce");*/
    	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        (: fog :)
          }));
	setup();
}

int fog()
{
remove_call_out("hurting");
message_vision( HIR "\n\n$N口一张，喷出一片朱红色的雾。\n\n" NOR,
this_object());
call_out("hurting",random(5)+2);

        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIM "\n\n你猝不及防，吸了一口毒气，只觉眼前发黑，腿脚发软。\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(100)+100 ;
        inv[i]->receive_damage("kee",dam);
        inv[i]->receive_wound("kee",dam/4);
        COMBAT_D->report_status(inv[i]);
        }
        return 1;
}

void die()
{
	object who;
	object me=this_object();
	if( environment() ) {
		message("sound", "千年雪蛇见不是对手，把身往雪地中一钻，顿时不见。\n\n", environment());
	}
	destruct(this_object());
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 50);
	tell_object(ob, HIR "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
