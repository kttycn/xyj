#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "fool" }));
	set("title", "˼��������");
	set("age", 150);
	set("attitude", "peaceful");
	set("int", 1);
	set("per", 10);

	set("max_kee", 2000);
	set("max_sen", 2000);
	set("chat_chance", 20);
	set("chat_msg", ({
		"�����૵����������˼����꣬�����Ҹ���̤���ҽŻ�����̤������أ����ܻش�(answer)���𣿡�\n",
	}));
	add_temp("apply/damage", 20);
	add_temp("apply/armor", 20);
	setup();
}

void die()
{
	if (environment()) {
		message("sound", "\n������ȥ��...", environment());
		message("sound", "\n���ܿ���վ������...\n", environment());
		set("eff_gin", 2000);
		set("eff_kee", 2000);
		set("eff_sen", 2000);
		set("kee", 2000);
		set("gin", 2000);
		set("sen", 2000);
	}
}

void unconcious()
{
  die ();
}

void init()
{
	add_action("do_answer", "answer");
}

int do_answer(string arg)
{
	object who = this_player();
	object me = this_object();
	if( !present("fbook", who)) return notify_fail("����Ȼ����������֪���𰸣�\n");
	message_vision(CYN"�����ɻش𣺡��������ܼ򵥣�����ѽſ��ϾͿ���������\n", this_player());
	command("idiot "+ me->query("id"));
	command("papaya "+ me->query("id"));
	command("die "+ me->query("id"));
	write("˵�գ�������ʧ����Ӱ���٣�\n"NOR);
	destruct(me);
	return 1;
}