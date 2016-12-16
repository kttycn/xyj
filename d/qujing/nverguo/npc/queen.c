// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "������˪�ɺ�"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "����Ů��");
  set("gender", "Ů��");
  set("age", 23);
  set("long", "������˪�ɺ���Ů��\n");
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
	command("chat "+who->query("name")+"Ѱ�������������������±�����棡");
	message("channel:chat",HIW"������ն����������˪�ɺ�(Xiliang xianhou)��"+who->query("name")+"��������ȡ����ʮ�Źأ�\n"NOR,users());
	tell_object(who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�");
	who->save();
	message_vision (HIY NAME+"��һ�������������ʧ��\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"ͻȻ�Ӱ�����������$Nҡҡͷ��"+
                  "���Ѵ���������һ���ˡ���ȥ����ȡ���ɡ�\n" NOR,who);
  message_vision (HIY "˵��"+NAME+"��һ�������������ʧ��\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"��һ�Ű������Գ�������$N��"+
                  "����δ����������һ�أ��Բ���\n" NOR,who);
  message_vision (HIY "˵�հ���ӵ��"+NAME+"�ڿ�����������ʧ��\n" NOR,who);
}
�
