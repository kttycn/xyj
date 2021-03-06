//puti.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string avenge();
string ask_chuxian(object me);
string ask_cancel();

void create()
{
	set_name("地藏王菩萨", ({"dizang pusa", "pusa"}));
	set("long", "面如朱玉，大耳垂肩，一脸肃静．
他便是主管阴曹地府，天下鬼魂的地藏王菩萨．\n");
	set("gender", "男性");
	set("class", "youling");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30+random(5));
	set("nkgain",790);
	set("max_kee", 3000);
	set("max_gin", 2500);
	set("max_sen", 2000);

	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 200);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 200);

	set("combat_exp", 2000000);
	set("daoxing", 4000000);

	set_skill("stick", 260);
	set_skill("kusang-bang", 260);
	set_skill("unarmed", 270);
	set_skill("whip", 300);
	set_skill("hellfire-whip", 300);
	set_skill("dodge", 280);
	set_skill("parry", 280);
	set_skill("literate", 250);
	set_skill("spells", 300);
	set_skill("force", 290);
	set_skill("tonsillit", 290);
	set_skill("ghost-steps", 280);
	set_skill("gouhunshu", 280);
	set_skill("jinghun-zhang", 270);
	set_skill("zhuihun-sword", 250);
	set_skill("sword", 250);

	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("dodge", "ghost-steps");
	map_skill("spells", "gouhunshu");
	map_skill("parry", "hellfire-whip");
	map_skill("whip", "hellfire-whip");
	map_skill("sword", "zhuihun-sword");
	map_skill("stick", "kusang-bang");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
		(: perform_action, "whip", "three" :),
		(: perform_action, "whip", "lunhui" :),
		(: cast_spell, "curse" :),
		(: cast_spell, "inferno" :),
		(: cast_spell, "heiwu" :),
		(: cast_spell, "hunfei" :)
	}) );
	set("nk_gain", 600);
	set("inquiry",([
		"招魂": (: ask_chuxian :),
		"kill": (: ask_chuxian :),
		"cancel": (: ask_cancel :),
		"复仇": (: avenge :)
	]));

	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);

	create_family("阎罗地府", 1, "你好");
	setup();

	carry_object("/d/obj/cloth/baipao")->wear();
	carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

string avenge()
{
	object who=this_player(),killer,where;
	string killid;
	if((string)who->query("family/family_name")!="阎罗地府")
		return ("你不是本派弟子，生死与本王何干？");
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
	tell_room(where,"只见地藏王菩萨向空中一指：\n");
	tell_room(where,"索魂小鬼何在，速去将"+killer->query("name")+"抓来。\n");
	tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓了起来！");
	killer->move(where);
	tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	command("say 大胆妖孽，胆敢杀害我阎罗地府弟子");
	this_object()->kill_ob(killer);
	return("拿命来。");
}
void attempt_apprentice(object ob, object me)
{
	if ( (string)ob->query("family/family_name")=="阎罗地府") {
		if (((int)ob->query("combat_exp") < 350000 )) {
			command("say " + RANK_D->query_rude(ob) + "这点三脚猫的把式也敢到我这里丢人现眼？");
			return;
		}
		command("grin");
		command("say 很好，" + RANK_D->query_respect(ob) +
			 "多加努力，他日必定有成。\n");
		command("recruit " + ob->query("id") );
		return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
		 "还是先去学些基础功夫吧！\n");
	return;
}

string ask_cancel()
{
	object me=this_player();
	if("/d/obj/yao/mieyao"->delete_mieyao(me))
		me->add("faith",-5);
	return ("没用的东西！");
}

string ask_chuxian(object me)
{
	me=this_player();
	if((string)me->query("family/family_name")=="阎罗地府") {
		if(me->query("faith")<100)
			return ("你还是先多加修炼为妙。");
		tell_room(environment(me),"地藏王菩萨脸上露出邪恶的笑容：\n");
		write(WHT+"/d/obj/yao/mieyao"->query_yao(me)+NOR);
		return HIB"多加努力，相信他日必定有成。\n"NOR;
	}
	return ("贫僧不明白。");
}
