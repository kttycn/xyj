//xueshanhufa4 by yushu 2000.11
#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIY"������"NOR,({ "busi niao", "hufa" }) );
	set("long", "һֻ�õ�����ķ�ˣ���˵�Ǵ����������µĵ����ɽ���\n");
	set("attitude", "friendly");
	set("max_gin", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("max_force", 1800);
	set("force", 3600);
	set("force_factor", 100);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 100);
	set("str", 30);
	set("cor", 30);
	set("cps", 25);
	set("combat_exp", 1200000);
	set("daoxing", 1200000);
	set_skill("dodge", 310);
	set_skill("parry", 310);
	set_skill("cuixin-zhang",310);
	set_skill("unarmed", 310);
	set_skill("xiaoyaoyou",310); 
	map_skill("unarmed","cuixin-zhang");
	map_skill("parry","cuixin-zhang");
	map_skill("dodge","xiaoyaoyou"); 
	setup();
}
/*
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
       HIR + "�����˸еĻ���ȼ���������������������з�����......\n\n" NOR, environment(),
	       this_object() );
	destruct(this_object());
}
*/
void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
HIR "��������Ļ���ȼ��������������ӻ����з��˳���......\n\n" NOR,environment(), this_object() );
       command("follow "+who->query("id"));
       command("protect "+who->query("id"));
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

void die()
{
  if (environment())
    message("sound", HIR"\n��������һ��������ȼ���������һ�\n"NOR, environment());

	set("eff_gin", 2000);
	set("eff_kee", 2000);
	set("eff_sen", 2000);
	set("force", 3600);
	set("mana", 3600);
	set("kee", 2000);
	set("gin", 2000);
	set("sen", 2000);
	
 }
void unconcious()
{
  die ();
}
