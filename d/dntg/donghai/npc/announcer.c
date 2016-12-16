// sgzl
#include <ansi.h>
#define NAME "东海龙王"

inherit NPC;

void create()
{
  set_name(NAME, ({"donghai longwang"}));
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
	who->set("dntg/donghai","done");
	who->add("daoxing",i+5000);
	who->add("score", 20);
	command("chat "+who->query("name")+"你竟敢拿走我龙宫的定海神针铁，看我不去玉帝面前告你！");
	tell_object(who,"你赢得了"+COMBAT_D->chinese_daoxing(i+5000)+"的道行！\n");
	message("channel:rumor", HIW"【月影神迹】听说"+who->name()+"("+who->query("id")+")顺利闯过大闹天宫第二关 ！！！ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed donghai-dragon on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
	who->save();
}


