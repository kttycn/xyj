// sgzl
#include <ansi.h>
#define NAME "马元帅"

inherit NPC;

void create()
{
  set_name(NAME, ({"ma yuanshuai"}));
  set("male", "男性");
  set("age", 23);
  set("long", "一只大马猴。\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  

  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragon-steps", 120);
  map_skill("dodge", "dragon-steps");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
}

void init()
{
  ::init();
}

void announce_success(object who)
{
	int i;

	i = random(500);
	who->add("dntg/number",1);
	who->set("dntg/huaguo","done");
	who->add("daoxing",i+4000);
	who->add("score", 20);
	command("chat "+who->query("name")+"斩了霸占我们水帘洞的魔头！");
	command("chat 从此七十二洞精灵皆应尊"+who->query("name")+"为王，随时听候调遣！");
	tell_object(who,"你赢得了"+COMBAT_D->chinese_daoxing(i+4000)+"的道行！\n");
	message("channel:rumor", HIW"【月影神迹】听说"+who->name()+"("+who->query("id")+")顺利闯过大闹天宫第一关 ！！！ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed huaguo-shan on %s\n",who->name(1), geteuid(who), ctime(time()) ) );

  message_vision (HIY NAME+"点头哈腰的对$N说到：这是我们众兄弟的一点儿小意思，不成敬意。\n" NOR,who);
  tell_object(who,"马元帅给你一个石头盘子。\n");
  who->save();
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"突然跑了过来$N摇摇头："+
                  "我们正在选猴王，没事别来捣乱。\n" NOR,who);
  message_vision (HIY "说罢"+NAME+"急匆匆的离开了。\n" NOR,who);
}

��
