//stone
// /d/guzhanchang/npc/xianhe.c

#include <ansi.h>

inherit __DIR__"beast.c";

void create()
{
        set_name(HIR"����ɺ�"NOR, ({ "xian he", "he" }) );
        set("race", "Ұ��");
        set("age", 30);
        set("long", "һֻ˶��İ׺ף�ͨ�������ѩ���׶���
����𣬳�����֣���צ�ƹ����ѽ���ʯ��\n");
        set("limbs", ({ "ͷ��", "����", "�Ȳ�", "���", "�ҳ�", "β��" }) );
        set("verbs", ({ "bite"}) );

	set("combat_exp", 1000000);
  	set("daoxing", 1000000);

	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("spells", 100);
	
	set("ride/need_train", 1);
  	set("ride/msg", "��");
  	set("ride/dodge", 100);

	set("max_kee", 1000);
	set("max_sen", 1000);
	set("mana", 2000);
	set("max_mana", 1000);
	set("mana_factor", 60);
	set("force", 2000);
	set("max_force", 1000);
	set("force_factor", 120);

        set_temp("apply/attack", 50);
        set_temp("apply/armor", 50);
	set_temp("apply/unarmed", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/dodge", 50);
        setup();
}



