#include <ansi.h>

inherit NPC;

void create()
{
  set_name(HIR"������"NOR, ({"huo qilin", "qilin"}));
  set("under_water",1);
  set("race", "Ұ��");
  set("age", 20);
  set("long", "һͷ˫���Ź⣬������˸����������ۡ�\n");
  set("combat_exp", 1000000);
  set("daoxing", 1100000);

  set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
  set("verbs", ({ "bite"}));

  set("max_kee", 800);
  set("kee", 800);
  set("max_sen", 900);
  set("sen", 900);

  set_skill("dodge", 150);
  set_skill("parry", 150);
  set_skill("unarmed", 150);

  set("ride/msg", "��");
  set("ride/dodge", 40);

  set_temp("apply/dodge", 100);
  set_temp("apply/attack", 100);
  set_temp("apply/armor", 100);

  setup();
}
