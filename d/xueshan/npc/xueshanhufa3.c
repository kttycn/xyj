//xueshanhufa2 by yushu 2000.11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIM"孔雀"NOR,({ "kong que", "hufa" }) );
	set("long", "一只得道多年的孔雀，传说是大鹏明王手下的得力干将。\n");
	set("attitude", "friendly");
	set("max_gin", 1400);
	set("max_kee", 1400);
	set("max_sen", 1400);
	set("max_force", 800);
	set("force", 1600);
	set("force_factor", 20);
	set("max_mana", 800);
	set("mana", 1600);
	set("mana_factor", 20);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 400000);
	set("daoxing", 400000);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("unarmed", 150);
	set_skill("xiaoyaoyou",150);
	set_skill("cuixin-zhang",150);
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
		HIM + "孔雀懒洋洋地甩了甩尾巴，一步三摇地踱走了。\n\n" NOR, environment(),		
	       this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
      HIM "你只觉得眼前一阵五彩缤纷，一只美丽的孔雀出现在你的面前。\n\n" NOR,environment(), this_object() );		
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
