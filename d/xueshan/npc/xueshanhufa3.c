//xueshanhufa2 by yushu 2000.11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIM"��ȸ"NOR,({ "kong que", "hufa" }) );
	set("long", "һֻ�õ�����Ŀ�ȸ����˵�Ǵ����������µĵ����ɽ���\n");
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
		HIM + "��ȸ�������˦��˦β�ͣ�һ����ҡ�������ˡ�\n\n" NOR, environment(),		
	       this_object() );
	destruct(this_object());
}
void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
      HIM "��ֻ������ǰһ������ͷף�һֻ�����Ŀ�ȸ�����������ǰ��\n\n" NOR,environment(), this_object() );		
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
