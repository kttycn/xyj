
#include <ansi.h>
inherit NPC;

void create() {

  set_name("太白金星",({"taibai jinxing"}));
  setup();
}

void announce(object winner,object env) {
  call_out("announce1",2,winner,env);
}

void announce1(object winner,object env)
{
	if (winner->query("dntg/lijing")!="done") {
		command("chat 奉玉帝圣旨，"+winner->query("name")+RANK_D->query_respect(winner)+
                  "武功盖世，法术超群，加封为齐天大圣！");
		command("rumor 城下之盟，丧权辱国，惨惨惨。。。");
		winner->add("cor",2);
		tell_object(winner,HIC"你得到了两点胆识！\n"NOR);
		winner->set_temp("apply/title",({HIR"齐天大圣"NOR}));
		winner->set("dntg/lijing","done");
		winner->add("dntg/number",1);
		winner->add("score", 20);
		message("channel:rumor", HIW"【月影神迹】听说"+winner->name()+"("+winner->query("id")+")顺利闯过大闹天宫第五关 ！！！ \n\n"NOR, users());
		log_file("dntg",sprintf("%s(%s) passed lijing on %s\n",winner->name(1), geteuid(winner), ctime(time()) ) );
		env->set("host",winner);
		winner->save();
	}
	destruct(this_object());
}
