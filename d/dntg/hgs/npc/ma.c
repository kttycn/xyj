// sgzl
#include <ansi.h>
#define NAME "ยํิชหง"

inherit NPC;

void create()
{
  set_name(NAME, ({"ma yuanshuai"}));
  set("male", "ฤะะิ");
  set("age", 23);
  set("long", "าปึปด๓ยํบ๏กฃ\n");
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
	command("chat "+who->query("name")+"ีถมหฐิีผฮารวหฎมฑถดตฤฤงอทฃก");
	command("chat ดำดหฦ฿สฎถþถดพซม้ฝิำฆื๐"+who->query("name")+"ฮชอ๕ฃฌหๆสฑฬýบ๒ต๗วฒฃก");
	tell_object(who,"ฤใำฎตรมห"+COMBAT_D->chinese_daoxing(i+4000)+"ตฤตภะะฃก\n");
	message("channel:rumor", HIW"กพิยำฐษ๑ผฃกฟฬýหต"+who->name()+"("+who->query("id")+")หณภ๛ดณนýด๓ฤึฬ์นฌตฺาปนุ ฃกฃกฃก \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed huaguo-shan on %s\n",who->name(1), geteuid(who), ctime(time()) ) );

  message_vision (HIY NAME+"ตใอทนþัüตฤถิ$NหตตฝฃบีโสวฮารวึฺะึตÜตฤาปตใถ๙ะกาโหผฃฌฒปณษพดาโกฃ\n" NOR,who);
  tell_object(who,"ยํิชหงธ๘ฤใาปธ๖สฏอทลฬืำกฃ\n");
  who->save();
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"อปศปลÜมหนýภด$Nากากอทฃบ"+
                  "ฮารวีýิฺักบ๏อ๕ฃฌรปสยฑ๐ภดตทยากฃ\n" NOR,who);
  message_vision (HIY "หตฐี"+NAME+"ผฑดาดาตฤภ๋ฟชมหกฃ\n" NOR,who);
}

ÿÿ
