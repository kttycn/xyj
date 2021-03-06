//xueshanhufa3 by yushu 2000.11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIG"凤凰"NOR,({ "feng huang", "hufa" }) );
	set("long", "一只得道多年的凤凰，传说是大鹏明王手下的得力干将。\n");
	set("attitude", "friendly");
	set("max_gin", 1700);
	set("max_kee", 1700);
	set("max_sen", 1700);
	set("max_force", 1100);
	set("force", 2200);
	set("force_factor", 40);
	set("max_mana", 1100);
	set("mana", 2200);
	set("mana_factor", 40);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 800000);
	set("daoxing", 800000);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("xiaoyaoyou",200);
	set_skill("cuixin-zhang",200);
	map_skill("unarmed","cuixin-zhang");
	map_skill("parry","cuixin-zhang");
	map_skill("dodge","xiaoyaoyou"); 
	setup();
}
int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}
void leave()
{
	message("vision",
		HIG + "凤凰无聊地打了个哈欠，无聊地朝四周看了看，无聊地飞走了。\n\n" NOR, environment(),		
	       this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
      HIG "突然间四周百鸟齐鸣，一只凤凰傲然站立在你的面前。\n\n" NOR,environment(), this_object() );
       enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}
