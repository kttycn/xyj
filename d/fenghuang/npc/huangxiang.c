#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("黄祥", ({ "huang xiang", "huang" }));
	set("nickname", HIW "天生神力" NOR);
	set("age", 25);
	set("title", HIR "猛龙将军" NOR);
	set("gender", "男性");
	set("long", "他是宗主的亲传弟子，掌法了得，臂力惊人，人称猛龙将军。\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "将军");
	set("per", 22);
	set("str", 32);
	set("int", 25);
	set("con", 30);


	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 1500);
	set("mana", 3000);
	set("mana_factor", 90);
	set("daoxing", 2000000);
	set("combat_exp", 800000);
	set("score", -5000);

	set_skill("literate", 100);
	set_skill("unarmed",140);
	set_skill("dodge", 110);
	set_skill("parry", 130);
	set_skill("force", 140);
	set_skill("wuzu-xinfa", 140);
	set_skill("fenghuang-shenfa", 140);
	set_skill("tenglong-finger",140);
	set_skill("spells", 120);
	set_skill("yufeng-shu", 120);
	map_skill("spells", "yufeng-shu");
	map_skill("unarmed","tenglong-finger");
	map_skill("parry", "tenglong-finger");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("凤凰星",3,"大将");
	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "凤凰星")
	{
		message_vision("黄祥对着$N点点头，微微笑了笑。\n",ob);
		return;
	}
}

void attempt_apprentice(object ob)
{
	ob = this_player();
	if (!(int)this_player()->query("bmark/毕业生"))
		command("say 你还是去凤凰军校去进修一下吧。\n");
	else
	{
		command("say 好吧，我收下你。\n");
		command("recruit "+ob->query("id"));
		return;
	}
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIC"凤凰城国防军少校"NOR);
	}
	return 0;
}
