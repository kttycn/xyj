// minger.c...yushu, 2000.10.24.

inherit NPC;
void create()
{
	set_name("明儿", ({"ming er", "er", "minger"}));
	set("gender", "女性" );
	set("age", 22);
	set("per", 30);
	set("long", "蜀山剑派的第四代弟子。\n");
	set("class", "swordsman");
	set("combat_exp", 150000);
	set("daoxing", 200000);
	set("attitude", "peaceful");
	create_family("蜀山剑派", 4, "弟子");
	set_skill("dodge", 100);
	set_skill("seven-steps", 100);
	set_skill("parry", 70);
	set_skill("whip", 80);
	set_skill("yujianshu", 80);
	set_skill("yiruwhip", 80);
	set_skill("force", 70);   
	set_skill("zixia-shengong", 80);
	set_skill("literate", 120);
	set_skill("spells", 80);
	set_skill("taoism", 80);
	set_skill("unarmed", 70);
	set_skill("hunyuan-zhang", 70);
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("spells", "taoism");
	map_skill("force", "zixia-shengong");
	map_skill("whip", "yiruwhip");
	map_skill("parry", "yiruwhip");
	map_skill("dodge", "seven-steps");
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
	carry_object("d/obj/weapon/whip/whip")->wield();
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
			command("blush");
			command("say 你比松儿好!\n");
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

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "swordsman");
}
