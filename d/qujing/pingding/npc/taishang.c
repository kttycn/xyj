// rewritten by snowcat on 4.12.1997
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("太上老君", ({"taishang laojun", "taishang", "laojun"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("daoxing", 10000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("dao", 180);
  set_skill("puti-zhi", 180);
  set_skill("jindouyun", 180);
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("spells", "dao");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",1800);
  set("max_force",1800);
  set("max_mana",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
	int i;

	if (who->query("combat_exp") < 10000)
		return;
	if (who->query("obstacle/pingding") == "done")
		return;
	if (! who->query_temp("obstacle/pingding_huaqi_killed"))
		return;
	if (! who->query_temp("obstacle/pingding_laonai_killed"))
		return;
	if (! who->query_temp("obstacle/pingding_jinjiao_killed"))
		return;
	if (! who->query_temp("obstacle/pingding_yinjiao_killed"))
		return;
	i = random(700);
	who->add("obstacle/number",1);
	who->set("obstacle/pingding","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"平顶山压龙山施威，替老夫收回金银童子！");
	message("channel:chat",HIW"【过关斩将】太上老君(Taishang laojun)："+who->query("name")+"闯过西行取经第十二关！\n"NOR,users());
	tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	who->save();
}

