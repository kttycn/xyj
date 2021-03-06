
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string avenge();
int ask_love();
void create()
{
	set_name(MAG"紫霞仙子"NOR, ({"zixia xianzi", "zixia", "xianzi","master"}));
	set("long", "她就是盘丝洞的开山祖师,传说她是佛祖的一棵灯芯。随佛祖修道悟
真,后来思凡下界占了花果山一处洞府,开山立派,传授门徒。\n");
	set("title", HIB"盘丝大仙"NOR);
	set("gender", "女性");
	set("age", 20);
	set("class","xian");
	set("attitude", "friendly");
	set("rank_info/respect", "小姑娘");
	set("cor", 30);
	set("per", 40);
	set("max_kee", 4500);
	set("max_gin", 800);
	set("max_sen", 4500);
	set("force", 5000);
	set("max_force", 3000);
	set("force_factor", 125);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 250);
	set("combat_exp", 3000000);
	set("daoxing", 4000000);

	set_skill("literate", 280);
	set_skill("unarmed", 300);
	set_skill("dodge", 290);
	set_skill("force", 280);
	set_skill("parry", 280);
	set_skill("sword", 280);
	set_skill("spells", 270);
	set_skill("whip", 300);
	set_skill("pansi-dafa", 270);
	set_skill("lanhua-shou", 280);
	set_skill("jiuyin-xinjing", 280);
	set_skill("chixin-jian", 280);
	set_skill("qin", 280);
	set_skill("yueying-wubu", 280);
	set_skill("yinsuo-jinling", 300);
	map_skill("spells", "pansi-dafa");
	map_skill("unarmed", "lanhua-shou");
	map_skill("force", "jiuyin-xinjing");
	map_skill("sword", "chixin-jian");
	map_skill("parry", "yinsuo-jinling");
	map_skill("dodge", "yueying-wubu");
	map_skill("whip", "yinsuo-jinling");
	set("chat_chance_combat", 50);
	 set("chat_msg_combat", ({
		  (: cast_spell, "wuzhishan" :),
		  (: cast_spell, "ziqi" :)
	 }) );
	set("inquiry", ([
		"复仇" : (: avenge :),
		"爱神" : (: ask_love :),
]));
create_family("盘丝洞", 1, "红");
setup();

	 carry_object("/d/obj/cloth/tianyi.c")->wear();
	 carry_object("/d/pansi/obj/ziqing.c")->wield();
	 carry_object("/d/ourhome/obj/shoes")->wear();
}

void attempt_apprentice(object ob)
{

	if ( (string)ob->query("family/family_name")=="盘丝洞") {
		if (((int)ob->query("combat_exp") < 1000000 )) {
			command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
			return;
		}
		command("pat "+ob->query("id"));
		command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，他日帮我杀了那个臭猴子。\n");
		command("recruit " + ob->query("id") );
		ob->set("title", "花果山盘丝大仙护法");
		ob->set("class", "xian");
		return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
	return;
}
int accept_fight(object me)
{
	return 0;
}

int ask_love()
{
	 object ob=this_player();
	 if(ob->query("family/family_name") != "盘丝洞")
	 {
	 command("say 你又不是盘丝洞的，学它做什么?");
	 return 1;
	 }
	 if(ob->query("family/master_name")!= this_object()->query("name"))
	 {
	 command("say 你又不是我的徒弟，谁管你！");
	 return 1;
	 }
	 if(!ob->query("pansi/love_master"))
	 {
	 ob->set("pansi/love_master",1);
	 command("say 这一招爱神，是为师多年修炼所悟，应该可以帮你保命的！");
	 ob->set("pansi/ask_zixia_go", 1);
	 return 1;
	} else
	{
	 command("say 这一招爱神，我不是已经传给你了吗?");
	 return 1;
	}
}
string avenge()
{
	 object who=this_player(),killer,where;
	 string killid;
	 if((string)who->query("family/family_name")!="盘丝洞")
	 return ("你不是本派弟子，生死与我何干？");
	 if(who->query("faith")<1000)
	 return ("你在本门名望还不够，还需多加努力才行。");
	 if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
	 return ("本座未闻死讯");
	 killid=who->query("kill/last_killer");
	 killer=find_living(killid);
	 if(!killer||!userp(killer))
	 return ("这个嘛，本座还得想一想");
	 command("say 本座这就去为你抱仇。");
	 who->set("avenge/mud_age",who->query("mud_age"));
	 where=environment(who);
	 tell_room(where,"只见紫霞仙子向空中一指：\n");
	 tell_room(where,"护法天尊何在，速去将"+killer->query("name")+"抓来。\n");
	 tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
	 killer->move(where);
	 tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
	 command("say 孽障，胆敢杀害我盘丝洞弟子");
	 this_object()->kill_ob(killer);
	 return("拿命来。");
}
