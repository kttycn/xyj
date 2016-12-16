//snake.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(RED"��ͷ����"NOR, ({ "ju mang", "snake" }) );
	set("race", "Ұ��");
	set("age", 20);
	set("long", "һֻ�����������Ȼ������������ȫ����࣬����Ҫһ�ڰ������¡�\n");
	set("attitude", "aggressive");
	set("kee", 1000);
	set("max_kee", 1000);
	set("sen", 1000);
	set("max_sen", 1000);
	set("max_mana",1000);
	set("max_force",1000);
	set("mana",1000);
	set("force",1000);
	set("str", 86);
	set("cor", 80);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);

	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&      (int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 30);
	tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}
