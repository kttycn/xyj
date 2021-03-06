// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string avenge();

void create()
{
	set_name(HIW"孔武大帝"NOR, ({"master dadi", "dadi", "master"}));
	set("long", "中国五千年传奇人物，自盘古开天以来便掌管着所有的武技。\n");
	set("title", HIC"武帝圣君"NOR);
	set("gender", "男性");
	set("age", 100);
	set("class", "wusheng");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("rank_info/respect", "大帝");
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("max_kee", 6000);
	set("max_gin", 1000);
	set("max_sen", 6000);
	set("force", 6000);
	set("max_force", 3000);
	set("force_factor", 150);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 150);
	set("combat_exp", 2500000);
	set("daoxing", 7500000);

	set_skill("unarmed", 270);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("spells", 290);  
	set_skill("feisheng-spells", 290);
	set_skill("literate", 280);
	set_skill("sword", 300);
	set_skill("wuying-sword", 300);
	set_skill("fumobashi", 280);  
	set_skill("mizong-steps", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("xiantian-force", 280);

	map_skill("spells", "feisheng-spells");
	map_skill("unarmed", "fumobashi");
	map_skill("force", "xiantian-force");
	map_skill("sword", "wuying-sword");
	map_skill("parry", "wuying-sword");
	map_skill("dodge", "mizong-steps");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: cast_spell, "feixian" :),
		(: perform_action, "sword", "juechen" :),
		(: perform_action, "sword", "fenge" :),
	}) );
	set("inquiry", ([
		"复仇" : (: avenge :),
	]));

	create_family("武圣门", 1, "尊者");
	
	setup();
	carry_object("/d/obj/cloth/writepao")->wear();
	carry_object("/d/qujing/huangfeng/obj/jinyipifeng")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object ob)
{
	ob=this_player();
	if( (string)ob->query("family/family_name")=="武圣门") {
		if ((int)ob->query("daoxing") < 500000 ) {
  			command("say 我们降魔除妖之人最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
			return;
		}
/*
		if( (int)ob->query("pending/kick_out")) {
			command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
			command("sigh");
			return;
		}
*/
		if ((int)ob->query_int() < 40) {
			command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
			command("sigh");
			return;
		}
		if( (int)ob->query_skill("feisheng-spells", 1) < 120 ) {
			command("say 这位" + RANK_D->query_respect(ob) + "对我飞升大法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
			command("sigh");
			return;
		}
		command("smile");
		command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
	return;
}
int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
	ob->set("class", "wusheng");
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="武圣门")
		return ("你不是本门弟子，生死与我何干？");
	if(who->query("faith")<1000)
		return ("你在本门名望还不够，还需多加努力才行。");
	if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
		return ("本王未闻死讯");
	killid=who->query("kill/last_killer");
	killer=find_living(killid);
	if(!killer||!userp(killer))
		return ("这个嘛，本王还得想一想");
	command("say 本王这就去为你抱仇。");
	who->set("avenge/mud_age",who->query("mud_age"));
	where=environment(who);
	tell_room(where,"只见孔武大帝向空中一指：\n");
	tell_room(where,"护法何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我武圣门弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
