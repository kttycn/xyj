inherit NPC;
#include <ansi.h>
int test_player();
void create()
{
	set_name("����", ({ "zhou wang", "zhou" }));
	set("long", "���ѵ����ǵ����ӹ�޵����������������ô�������³���\n");
	set("gender", "����");
	set("age", 47);
	set("attitude", "heroism");
	set("per", 30);
	set("max_kee", 700);
	set("max_gin", 700);
	set("max_sen", 700);
	set("force", 700);
	set("max_force", 700);
	set("force_factor", 60);
	set("max_mana", 700);
	set("mana", 400);
	set("mana_factor", 60);
	set("combat_exp", 410000);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("force", 50);
	set_skill("spells", 50);
	set_skill("unarmed", 50);
	set_skill("tonsillit", 50);
	set_skill("ghost-steps", 50);
	set_skill("jienan-zhi", 50);
	map_skill("unarmed", "jienan-zhi");
	map_skill("force", "tonsillit");
	set("inquiry", ([
		"name" : "�����̳�����Ҳ��������һ��檡�",
		"���" : (: test_player :),
		"槼�" : (: test_player :),
		"槼�" : (: test_player :),
	]));

	setup();
	carry_object("/d/obj/cloth/gongpao")->wear();
	carry_object("/d/qujing/biqiu/obj/ring")->wear();
}
int test_player ()
{
	object me = this_object();
	object who = this_player();

	if (who->query("daoxing") < 10000)
	{
		message_vision ("$N��$n˵������ż�����У��������ſڴƻƣ�\n",me,who);
		message_vision ("\n$N�����ҷԸ��˼��䡣\n",me);
		who->move("/d/city/center");
		return 1;
	}
	if (who->query("obstacle/xuanyuan")=="done")
	{
		command("fear");
		command("sigh");
		return 1;
	}
	if (who->query_temp("can_in"))
	{
		message_vision (CYN"$N��$n˵��������Բ������ǳ����Ľ�ɽѽ������������檣�\n"NOR,me,who);
		remove_call_out ("following");
		call_out ("following",2,me,who);
		return 1;
	}
}

void following (object me,object who)
{
//	object taijian1 = present ("tai jian 1",environment(me));
//	object taijian2 = present ("tai jian 2",environment(me));

	message_vision ("����˵�����ɷ����ȥѰ����������ˣ�\n",who);
	command("sigh");
	message_vision ("$N������ʼ����$nһ���ж���\n",me,who);
	me->set_leader(who);
	who->set("mysaver",who);
//	if (taijian1)
//		message_vision ("$N������ʼ����$nһ���ж���\n",taijian1,who);
//	taijian1->set_leader(who);
//	if (taijian2)
//		message_vision ("$N������ʼ����$nһ���ж���\n",taijian2,who);
//	taijian2->set_leader(who);
	return;
}
