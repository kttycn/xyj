// songer.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("松儿", ({"song er", "er", "songer"}));
	set("gender", "男性" );
	set("age", 22);
	set("per", 30);
	set("long", "蜀山剑派的第四代弟子。\n");
	set("class", "swordsman");
	set("combat_exp", 120000);
	set("daoxing", 200000);
	set("attitude", "peaceful");
	create_family("蜀山剑派", 4, "弟子");
	set_skill("unarmed", 60);
	set_skill("dodge", 80);
	set_skill("seven-steps", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("yujianshu", 80);
	set_skill("hunyuan-zhang", 60);
	set_skill("force", 70);
	set_skill("zixia-shengong", 70);
	set_skill("literate", 80);
	set_skill("spells", 80);
	set_skill("taoism", 80);
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("sword", "yujianshu");
	map_skill("parry", "yujianshu");
	map_skill("dodge", "seven-steps");
	map_skill("unarmed", "hunyuan-zhang");
	set("max_kee", 500);
	set("max_sen", 500);
	set("force", 1000);
	set("max_force", 800);
	set("mana", 1600);
	set("max_mana", 800);	
	set("force_factor", 40);
	set("mana_factor", 40);

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="蜀山剑派" )
	{
		if( (int)ob->query("family/generation") < 3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
			else command("say 师姑见笑了。\n");
		}
		else if( (int)ob->query("family/generation") ==3  )
		{
			if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
			else command("say 师妹太客气了。\n");
		}
		else 
		{
			command("snicker");
			command("say 帮我问候一下明儿!\n");
			command("recruit " + ob->query("id") );
		}
	}

	else
	{
		command("say 好，我蜀山剑派一门人才辈出，你可得给师父争气。\n");
		command("recruit " + ob->query("id") );
	}

	return;
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting()
	&& !ob->query("env/invisibility") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}

void greeting(object ob)
{
	if( !ob || !present(ob, environment(this_object())) ) return;
	say( "松儿热情地说道：这位" + RANK_D->query_respect(ob) + "，欢迎来到蜀山！\n");
}
