
#include <ansi.h>
#define NAME "天蓬元帅"

inherit NPC;

void create()
{
  set_name(NAME, ({"tian peng yuan shuai"}));
  set("male", "男性");
  set("age", 23);

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
	who->set("dntg/bmw","done");
	who->add("daoxing",i+5000);
	who->add("score", 20);
	command("chat 好你个 "HIR+who->query("name")+HIC" 你不好好作你的弼马温，却到天河俺老猪这来捣乱，你给我走着瞧！！");
	tell_object(who,HIY"你赢得了 "HIR+COMBAT_D->chinese_daoxing(i+5000)+HIY"的道行 ！！！\n"NOR);
	message("channel:rumor", HIW"【月影神迹】听说"+who->name()+"("+who->query("id")+")顺利闯过大闹天宫第四关 ！！！ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed bima-weng on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
	who->save();
}

