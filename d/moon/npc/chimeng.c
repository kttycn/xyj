//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("痴梦仙姑",({"chi meng","dream", "fairy"}));
	set("long",
"此乃迷津痴梦仙姑也；不受金银之谢，但遇有缘者渡之！\n");
	set("title", "迷津渡者");
	set("gender", "女性");
	set("age", 18);
	set("class", "xian");
	set("attitude", "friendly");
	set("rank_info/respect", "仙姑");
	set("per", 30);
	set("int", 30);
	set("max_kee", 1000);
	set("max_gin", 1000);
	set("max_sen", 1000);

	set("force", 8000);
	set("max_force", 4000);
	set("force_factor", 150);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 140);
	set("combat_exp", 1000000);
	set("daoxing", 500000);


	set("eff_dx", 100000);
	set("nkgain", 300);

	set_skill("literate", 190);
	set_skill("unarmed", 180);
	set_skill("dodge", 200);
	set_skill("force", 220);
	set_skill("parry", 220);
	set_skill("whip", 280);
	set_skill("unarmed", 180);
	set_skill("spells", 220);
	set_skill("baihua-zhang", 220);
	set_skill("moonshentong",240);
	set_skill("jueqing-whip", 280);
	set_skill("moonforce", 220);
	set_skill("moondance", 200);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("whip", "jueqing-whip");
	map_skill("parry", "jueqing-whip");
	map_skill("dodge", "moondance");

	create_family("月宫", 2, "弟子");
	setup();

	carry_object("/d/obj/cloth/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("title")=="广寒宫传人")
	{
		command("jump");
		command("say 既然掌门姐姐愿意与我学习,我很高兴!\n");
		command("recruit " + ob->query("id") );
		return;
	}
	if ( !((string)ob->query("gender")=="女性")){
		command("shake");
		command("say 我们月宫只收女徒，这位" +
		RANK_D->query_respect(ob) + "还是另请高就吧。\n");
		return ;
	}
	if (random(this_player()->query_kar()) < 20 || this_player()->query("mark/moon_chimeng")){
		this_player()->set("mark/moon_chimeng", 1);
		command("shake");
		command("say 你我无缘，还是另请高就吧。\n");
		return ;
	}
	else{
		command("pat "+ob->query("id"));
		command("say 既然" + RANK_D->query_respect(ob) +
"与我有缘，我就收下你了。\n");
		command("recruit " + ob->query("id") );
		return ;
	}
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}
