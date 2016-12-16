//Cracked by Roath
// rewritten by snowcat on 12.12.1997

inherit NPC;
#include <ansi.h>
void create()
{
  set_name("������", ({"li tianwang", "li", "tianwang"}));
  set("gender", "����");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("daoxing", 2000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);
  set_skill("spells",180);
  set_skill("buddhism", 180);
  set_skill("jienan-zhi", 180);
  set_skill("lotusmove", 180);
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",1800);
  set("max_force",1800);
  set("max_mana",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/armor/jinjia")->wear();

}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/jilei") == "done")
    return;
  if (who->query("obstacle/firemount") != "done")
    return;
  if (! who->query_temp("obstacle/jilei_yumian_killed"))
    return;
  if (! who->query_temp("obstacle/jilei_niumo_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/jilei","done");
  who->add("combat_exp",i+4000);
	who->add("score", 10);
  command("chat "+who->query("name")+"����ɽ����ͨ��Ħ�ƶ���ţħ��");
message("channel:chat",HIW"������ն����������(Li tianwang)��"+who->query("name")+"��������ȡ���ڶ�ʮ���أ�\n"NOR,users());
  tell_object (who,"��Ӯ����"+COMBAT_D->chinese_daoxing(i+4000)+"�ĵ��У�\n");
  who->save();
}


