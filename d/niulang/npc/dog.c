// By canoe 2001.03.25
inherit NPC;
 
void create()
{
	set_name("����Ȯ", ({ "xiaotian quan" }) );
	set("long", 
		"��꯵�����Ȯ��\n"
	);
	set("race", "Ұ��");
	set("title","�����ɷ");
	set("age", 400);
	set("str", 25);
	set("int", 20);
	set("per", 15+random(10));
	set("combat_exp", 270000);
	set("daoxing", 50000);
	set("attitude", "friendly");
	set("max_kee", 2000);
	set("max_sen", 2000);
	set("force",2000);
	set("max_force",2020);
	set("force_factor", 100);
	set("mana", 200);
	set("max_mana", 200);
	set("mana_factor", 20);
	set_skill("dodge",260);
	set_skill("dragon-steps",260);
	set_skill("dragonfight",260);
	set_skill("unarmed",260);
	map_skill("unarmed","dragonfight");
	map_skill("parry","dragonfight");
	map_skill("dodge","dragon-steps");
	set("limbs", ({ "ͷ��", "����", "��", "β��",}) );
	set("verbs", ({ "bite", "claw" }) );
	setup();
}
 
void heart_beat() {
       
	set("eff_kee", 2000);
	set("eff_sen", 2000);
	set("kee",2000);
	set("sen",2000);
	set("force",2000);

	::heart_beat();
}
