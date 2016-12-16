// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit NPC;

void create()
{
	string name;
	set_name(HIY"���꾫"NOR,({"fox"}));
	set("race", "Ұ��");
	set("age", 20);
	set("long", "һֻ�ƻ��ĺ��ꡣ\n");
	set("str", 40);
	set("cor", 30);
	set("con", 30);
	set("cps", 30);
	set("spi", 30);
	set("int", 30);
	set_temp("apply/damage", 25);
	set_temp("apply/armor", 50);
	set("max_kee", 1200);
	set("max_sen", 1200);
	set("force", 1000);
	set("max_force", 1000);
	set("force_factor", 10);
	set("mana", 1000);
	set("max_mana", 1000);
	set("mana_factor", 50);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("fox-hand", 50);
	set_skill("huxing-steps", 50);
	map_skill("unarmed", "fox-hand");
	map_skill("dodge", "huxing-steps");
	set("combat_exp", 100000);
	set("limbs", ({ "ͷ��", "����", "ǰצ", "β��", "��Ƥ", "��צ"}) );
	set("verbs", ({ "bite", "claw"}) );
	set_weight(500);

	setup();
	create_family("��ԯ��Ĺ",3,"����");
}

void copy_status(object me,object ob)
{
	me->set_skill("unarmed", (int)ob->query_skill("unarmed", 1));
	me->set_skill("dodge", (int)ob->query_skill("dodge", 1));
	me->set_skill("parry", (int)ob->query_skill("parry", 1));
	me->set_skill("fox-hand", (int)ob->query_skill("fox-hand",
1) + 20);
	me->set_skill("huxing-steps", (int)ob->query_skill("huxing-steps", 1)
+ 20);

	me->set("combat_exp",ob->query("combat_exp"));
	me->set("daoxing",ob->query("daoxing"));
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
		HIB + name() +"һ��β�ͣ�˲�����ʧ�ˡ�\n"
		NOR,environment(),  this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	object me=this_object();
	me->set("possessed",who);
	copy_status(me,who);
	message("vision", HIR"��Ȼһ�����紵����һֻ"+ name() +
"�����������ǰ��\n\n"NOR,environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) )
				enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
}
