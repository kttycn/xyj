#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("蓝任", ({ "lan ren", "lan" }));
	set("nickname", HIR "极乐天下" NOR);
	set("age", 25);
	set("title", HIY "极乐将军" NOR);
	set("gender", "男性");
	set("long", "他是宗主的亲传弟子，刀法了得，以刀法得名，人称极乐将军。\n");
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "将军");
	set("per", 29);
	set("str", 32);
	set("int", 25);
	set("con", 30);

	set("max_kee", 1000);
	set("max_gin", 500);
	set("max_sen", 1000);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 100);
	set("max_mana", 2000);
	set("mana", 4000);
	set("mana_factor", 100);
	set("daoxing", 3000000);
	set("combat_exp", 400000);
	set("score", 1);

	set_skill("literate", 100);
	set_skill("blade", 140);
	set_skill("unarmed",110);
	set_skill("dodge", 110);
	set_skill("parry", 110);
	set_skill("force", 120);
	set_skill("jile-dao",140);
	set_skill("wuzu-xinfa", 140);
	set_skill("fenghuang-shenfa", 110);
	set_skill("spells", 130);
	set_skill("yufeng-shu", 130);
	map_skill("spells", "yufeng-shu");
	map_skill("blade","jile-dao");
	map_skill("parry", "jile-dao");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("force", "wuzu-xinfa");

	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 40);
	set_temp("apply/armor", 80);

	create_family("凤凰星",3,"大将");
	set("chat_chance", 1);
	set("chat_msg", ({
		"蓝任叹了口气道：“唉 …… 不知最近宗主是怎么了?……”\n",
		"好象变了一个人似的。\n",
    }));

	setup();
	carry_object("/d/fenghuang/obj/pixue")->wear();
	carry_object("/d/fenghuang/obj/junfu")->wear();
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	if ((string)ob->query("family/family_name") == "凤凰星")
	{
		message_vision("蓝任对着$N点点头，微微笑了笑。\n",ob);
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
