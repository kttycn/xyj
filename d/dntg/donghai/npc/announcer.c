// sgzl
#include <ansi.h>
#define NAME "��������"

inherit NPC;

void create()
{
  set_name(NAME, ({"donghai longwang"}));
  set("male", "����");
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
	command("chat "+who->query("name")+"�㾹�������������Ķ��������������Ҳ�ȥ�����ǰ���㣡");
	tell_object(who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+5000)+"�ĵ��У�\n");
	message("channel:rumor", HIW"����Ӱ�񼣡���˵"+who->name()+"("+who->query("id")+")˳�����������칬�ڶ��� ������ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed donghai-dragon on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
	who->save();
}


