// gao.c
#include <ansi.h>
inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("����", ({"guo wang", "wang", "king"}));
  set("long", "ͷ��һ������ڣ�����һ�����������һ�������������ۡ�\n");
  set("title", "�ڼ���");
  set("gender", "����");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("daoxing", 200000);

  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("parry", 100);
  set("max_gin",800);
  set("max_kee",800);
  set("max_sen",800);
  set("max_force",1000);
  set("max_mana",1000);
  set("force_factor",120);
  set("eff_dx",15000);
  set("nkgain",90);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success()
{
  object me = this_object();
  object where = environment(me);
  string id = me->query("my_saver");
  object who;

  if (! id)
    return;

  who = present(id,where);
  if (! who)
    return;

  remove_call_out ("announce");
  call_out ("announce",8,me,who);
}

void announce(object me, object who)
{
	int i;

	if (who->query_temp("obstacle/wuji") != "saved")
		return;

	if (who->query("obstacle/wuji") == "done")
		return;

	i = random(600);
	who->add("obstacle/number",1);
	who->set("obstacle/wuji","done");
	who->add("daoxing",i+4000);
	who->add("score", 10);
	command("thank "+who->query("id"));
	command("chat "+who->query("name")+"�ڼ������һ�����������������Ǭ����");
	message("channel:chat",HIW"������ն��������(Guo wang)��"+who->query("name")+"��������ȡ����ʮ���أ�\n"NOR,users());
	tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
	who->save();
	command("follow none");
}

