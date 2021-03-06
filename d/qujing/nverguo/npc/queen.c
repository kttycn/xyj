// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "西梁披霜仙后"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "晨曦女神");
  set("gender", "女性");
  set("age", 23);
  set("long", "西梁披霜仙后晨曦女神。\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragon-steps", 120);
  map_skill("dodge", "dragon-steps");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
	int i;

	i = random(500);
	if (who->query("obstacle/nverguo") == "done")
		return;
	who->add("obstacle/number",1);
	who->set("obstacle/nverguo","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("chat "+who->query("name")+"寻回西梁国宝，西梁上下奔走相告！");
	message("channel:chat",HIW"【过关斩将】西梁披霜仙后(Xiliang xianhou)："+who->query("name")+"闯过西行取经第十九关！\n"NOR,users());
	tell_object(who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！");
	who->save();
	message_vision (HIY NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"突然从白雾中闪出向$N摇摇头："+
                  "您已闯过西梁这一关了。快去西天取经吧。\n" NOR,who);
  message_vision (HIY "说罢"+NAME+"在一阵白雾中徐徐消失。\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"从一团白雾中显出，告诉$N："+
                  "您尚未闯过西梁这一关，对不起。\n" NOR,who);
  message_vision (HIY "说罢白雾拥着"+NAME+"在空中慢慢地消失。\n" NOR,who);
}
�
