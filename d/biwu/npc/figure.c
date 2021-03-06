inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("无常", ({ "figure", "wuchang" }));
	set("title", "黑衣人");
	set("gender", "男性");
	set("age", 43);
	set("str", 20);
	set("cor", 20);
	set("long", "一个全身穿黑衣的家伙。\n");
	set("combat_exp", 1000000);
	set("attitude", "heroism");

	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set("max_kee",500);
	set("kee",500);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 15);

	set("force", 500); 
	set("max_force", 500);
	set("force_factor", 10);

	setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
	carry_object("/d/obj/cloth/cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) ) {
		kill_ob(ob);
	}
}



