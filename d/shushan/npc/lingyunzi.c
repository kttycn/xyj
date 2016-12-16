//ling yunzi-yushu 2000.10.24
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("凌云子", ({"ling yunzi", "yunzi", "zi"}));
	set("title", "蜀山剑派掌事弟子");   
	set("long", "蜀山剑派掌事弟子\n");
	set("gender", "男性");
	set("age", 37);
	set("attitude", "peaceful");
	set("class", "swordsman");
	set("str", 30);
	set("int", 30);
	set("per", 21);
	set("con", 30);
	set("combat_exp", 500000);
	set("daoxing", 500000);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("force", 3600);
	set("max_force", 1800);
	set("force_factor", 90);
	set("max_mana", 1800);
	set("mana", 3600);
	set("mana_factor", 90);
	set_skill("zixia-shengong", 120);
	set_skill("dodge", 120);
	set_skill("yujianshu", 130);
	set_skill("literate", 120);
	set_skill("sword", 120);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("spells", 150);
	set_skill("taoism", 140);
	set_skill("seven-steps", 120);
	set_skill("unarmed", 120);
	set_skill("hunyuan-zhang", 120);
	map_skill("unarmed", "hunyuan-zhang");
	map_skill("dodge", "seven-steps");
	map_skill("parry", "yujianshu");
	map_skill("sword", "yujianshu");
	map_skill("force", "zixia-shengong");
	map_skill("spells", "taoism");
	
	create_family("蜀山剑派", 3, "弟子");
	setup();
	carry_object("/d/lingtai/obj/pao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if( (string)ob->query("family/family_name")=="蜀山剑派") {
		if ((int)ob->query("daoxing") < 100000 ) {
  			command("say 你的道行还不够，" + RANK_D->query_respect(ob) + "还需多加努力才行。\n");
			return;
		}
		if( (int)ob->query_skill("taoism", 1) < 80 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "你的天师仙法还不到火候,你还是找松儿他们练着吧!\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say 你是本派的吗?，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) ) {
		ob->set("class", "swordsman");
		ob->set("title", "蜀山剑派第四代弟子");
	}
	return 0;
}
