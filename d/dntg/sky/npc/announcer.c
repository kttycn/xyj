
#include <ansi.h>
#define NAME "����Ԫ˧"

inherit NPC;

void create()
{
  set_name(NAME, ({"tian peng yuan shuai"}));
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
	who->set("dntg/bmw","done");
	who->add("daoxing",i+5000);
	who->add("score", 20);
	command("chat ����� "HIR+who->query("name")+HIC" �㲻�ú�����������£�ȴ����Ӱ������������ң�����������ƣ���");
	tell_object(who,HIY"��Ӯ���� "HIR+COMBAT_D->chinese_daoxing(i+5000)+HIY"�ĵ��� ������\n"NOR);
	message("channel:rumor", HIW"����Ӱ�񼣡���˵"+who->name()+"("+who->query("id")+")˳�����������칬���Ĺ� ������ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed bima-weng on %s\n",who->name(1), geteuid(who), ctime(time()) ) );
	who->save();
}

