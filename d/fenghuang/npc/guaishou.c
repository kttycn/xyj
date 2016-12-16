#include <ansi.h>
inherit NPC;

int ask_me();
void create()
{
	object me;
	int myskill;
	me=this_player();
	myskill=me->query_skill("force");
	if (myskill<me->query_skill("unarmed"))
		myskill=me->query_skill("unarmed");
	if (myskill<me->query_skill("dodge"))
		myskill=me->query_skill("dodge");
	if (myskill<me->query_skill("parry"))
		myskill=me->query_skill("parry");
	myskill=myskill/2;
	set_name("����", ({ me->query("id")+"-guai","guai" }));
	set("age", 10);
	set("gender", "����");
	set("long", "һͷ�ص׹��ޡ�\n");
	set("attitude", "peaceful");
	set("kee", me->query("kee")/2);
	set("max_kee", me->query("max_kee")/2);
	set("sen", me->query("sen")/2);
	set("force", me->query("force")/2);
	set("max_force", me->query("max_force")/2);
	set("force_factor", me->query("max_force")/20);
	set("max_sen", me->query("max_sen")/2);
	set("str", me->query("str"));
	set("per", me->query("per"));
	set("killman",me->query("id"));
	set("combat_exp", me->query("combat_exp")/2);
	set_skill("unarmed",myskill);
	set_skill("dodge", myskill);
	set_skill("parry", myskill);
	set_skill("force", myskill);
	set_skill("tenglong-finger",myskill);
	set_skill("wuzu-xinfa", myskill);
	set_skill("fenghuang-shenfa", myskill);
	map_skill("unarmed","tenglong-finger");
	map_skill("parry", "tenglong-finger");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");
	setup();
}

void die()
{
	object  killer;
	int i,exp,pot;
	string skill;
	if( !living(this_object()) ) revive(1);
// Clear all the conditions by death.
	this_object()->clear_condition();

	COMBAT_D->announce(this_object(), "dead");
	if( objectp(killer = query_temp("last_damage_from")) ) {
		set_temp("my_killer", killer->query("id"));
		COMBAT_D->killer_reward(killer, this_object());
	}

	if (userp(killer) && killer->query("id")==this_object()->query("killman"))
	{
	   exp=random(200);
	   pot=random(100);
	   killer->add("combat_exp",exp);
	   killer->add("potential",pot);
	   killer->set_temp("digdong1",0);
	   killer->set_temp("digdong2",0);
	   killer->set_temp("digdong3",0);
	   killer->set_temp("digdong4",0);
	   killer->set_temp("digdong5",0);
	   killer->set_temp("digdong6",0);
	   tell_object(killer,sprintf(HIW"��õ���%d����ѧ���飬%d��Ǳ�� \n"NOR,exp,pot));  
	}
	this_object()->remove_all_killer();
	all_inventory(environment())->remove_killer(this_object());

	this_object()->dismiss_team();
	destruct(this_object());
}

