// rewritten by snowcat on 12.12.1997

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("陈长老", ({"chen zhanglao", "chen", "zhanglao"}));
	set("gender", "男性");
	set("age", 70);
	set("attitude", "friendly");
	set("combat_exp", 50000);
	set("daoxing", 50000);

	set("per", 35);
	set_skill("dodge", 30);
	set_skill("force", 30);
	set_skill("parry", 30);
	set("max_sen",600);
	set("max_gee",600);
	set("max_gin",600);
	set("force",500);
	set("max_force",500);
	set("max_mana",500);
	set("force_factor",5);
	setup();

	carry_object("/d/obj/cloth/choupao")->wear();

}

void announce_success (object who)
{
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/tongtian") == "done")
		return;
	if (! who->query_temp("obstacle/tongtian_killed"))
		return;
	i = random(800);
	who->add("obstacle/number",1);
	who->set("obstacle/tongtian","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"通天河救童男女，水宅降鱼精！");
	message("channel:chat",HIW"【过关斩将】陈长老(Chen zhanglao)："+who->query("name")+"闯过西行取经第十七关！\n"NOR,users());
	tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	who->save();
}

