
#include <ansi.h>
inherit NPC;

void create() {

  set_name("̫�׽���",({"taibai jinxing"}));
  setup();
}

void announce(object winner,object env) {
  call_out("announce1",2,winner,env);
}

void announce1(object winner,object env)
{
	if (winner->query("dntg/lijing")!="done") {
		command("chat �����ʥּ��"+winner->query("name")+RANK_D->query_respect(winner)+
                  "�书������������Ⱥ���ӷ�Ϊ�����ʥ��");
		command("rumor ����֮�ˣ�ɥȨ������ҲҲҡ�����");
		winner->add("cor",2);
		tell_object(winner,HIC"��õ������㵨ʶ��\n"NOR);
		winner->set_temp("apply/title",({HIR"�����ʥ"NOR}));
		winner->set("dntg/lijing","done");
		winner->add("dntg/number",1);
		winner->add("score", 20);
		message("channel:rumor", HIW"����Ӱ�񼣡���˵"+winner->name()+"("+winner->query("id")+")˳�����������칬����� ������ \n\n"NOR, users());
		log_file("dntg",sprintf("%s(%s) passed lijing on %s\n",winner->name(1), geteuid(winner), ctime(time()) ) );
		env->set("host",winner);
		winner->save();
	}
	destruct(this_object());
}
