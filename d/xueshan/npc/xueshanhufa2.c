//xueshanhufa.c by yushu 2000.11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIC"���"NOR,({ "shen diao", "hufa" }) );
	set("long", "һֻ�õ��������񣬴�˵�Ǵ����������µĵ����ɽ���\n");
	set("attitude", "friendly");
	set("max_gin", 1200);
	set("max_kee", 12000);
	set("max_sen", 1200);
	set("max_force", 600);
	set("force", 600);
	set("force_factor", 10);
	set("max_mana", 600);
	set("mana", 600);
	set("mana_factor", 10);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 200000);
	set("daoxing", 200000);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("unarmed", 100);
	set_skill("xiaoyaoyou",100);
	set_skill("cuixin-zhang",100);
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
		HIB + "���һ����ণ�չ������ˣ�\n\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIC "ֻ������л���һ����ɫ���磬һֻ�����˶�����\n\n" NOR,environment(), this_object() );
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
