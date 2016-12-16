// sgzl
#include <ansi.h>
#define NAME "��Ԫ˧"

inherit NPC;

void create()
{
  set_name(NAME, ({"ma yuanshuai"}));
  set("male", "����");
  set("age", 23);
  set("long", "һֻ����\n");
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
	command("chat "+who->query("name")+"ն�˰�ռ����ˮ������ħͷ��");
	command("chat �Ӵ���ʮ���������Ӧ��"+who->query("name")+"Ϊ������ʱ�����ǲ��");
	tell_object(who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	message("channel:rumor", HIW"����Ӱ�񼣡���˵"+who->name()+"("+who->query("id")+")˳�����������칬��һ�� ������ \n\n"NOR, users());
	log_file("dntg",sprintf("%s(%s) passed huaguo-shan on %s\n",who->name(1), geteuid(who), ctime(time()) ) );

  message_vision (HIY NAME+"��ͷ�����Ķ�$N˵���������������ֵܵ�һ���С��˼�����ɾ��⡣\n" NOR,who);
  tell_object(who,"��Ԫ˧����һ��ʯͷ���ӡ�\n");
  who->save();
}

void refuse_player(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"ͻȻ���˹���$Nҡҡͷ��"+
                  "��������ѡ������û�±������ҡ�\n" NOR,who);
  message_vision (HIY "˵��"+NAME+"���Ҵҵ��뿪�ˡ�\n" NOR,who);
}

��
