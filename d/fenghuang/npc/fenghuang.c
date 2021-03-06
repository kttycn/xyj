inherit NPC;
#include <ansi.h>;
inherit F_MASTER;

void create()
{
	set_name(HIC"凤"HIR"凰"NOR, ({ "feng huang", "feng" }));
	set("nickname", MAG "凤凰公主" NOR);
	set("long", 
		"她是原凤凰星的公主。\n"
		"她长的"HIW"宛如玉雕冰塑，似梦似幻，已不再是凡间人物.\n"NOR);
	set("gender", "女性");
	set("age", 22);
	set("class", "phoenix");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "公主");
	set("per", 100);
	set("str", 50);
	set("int", 55);
	set("con", 50);

	set("max_kee", 5000);
	set("max_gin", 1000);
	set("max_sen", 5000);
	set("force", 8000);
	set("max_force", 4000);
	set("force_factor", 250);
	set("max_mana", 4000);
	set("mana", 8000);
	set("mana_factor", 250);
	set("daoxing", 10000000);
	set("combat_exp", 10000000);
	set("score", 0);

	set_skill("force", 280);
	set_skill("wuzu-xinfa", 260);
	set_skill("yufeng-shu", 250);
	set_skill("dodge", 270);
	set_skill("fenghuang-shenfa", 270);
	set_skill("spells", 240);
	set_skill("parry", 280);
	set_skill("literate", 250);
	set_skill("unarmed",300);
	set_skill("tenglong-finger",300);
	set_skill("jile-dao", 280);
	set_skill("blade", 280);
	map_skill("force", "wuzu-xinfa");
	map_skill("dodge", "fenghuang-shenfa");
	map_skill("unarmed", "tenglong-finger");
	map_skill("parry", "tenglong-finger");
	map_skill("spells","yufeng-shu");
	map_skill("blade","jile-dao");

	create_family("凤凰星", 1, "公主");
	set("chat_chance", 1);
	set("chat_msg", ({
		HIC"凤"HIR"凰"NOR"嫣然一笑。\n",
	}) );

	setup();
	carry_object("/d/fenghuang/obj/jia")->wear();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("family/family_name")=="凤凰星") {
		if ( (int)ob->query("combat_exp") < 1000000 ) {
		  	command("say 你的修行还不够，对我的招法难以领悟。\n");
			return;
		}
		if( (int)ob->query("betray/phoenix")) {
			command("say 这位" + RANK_D->query_respect(ob) + "性情反复无常，我不原收你为徒！\n");
			command("sigh");
			return;
		}
		if( (int)ob->query_skill("wuzu-xinfa", 1) < 200 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "你的无祖心法还不到火候,你还是找各 位将军们练练吧!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say 很好，我就收下你了，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say 你是本城的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "phoenix");
		ob->set("title", HIY"凤凰城国防军少帅"NOR);
	}
	return 0;
}
