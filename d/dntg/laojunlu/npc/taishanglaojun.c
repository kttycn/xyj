
#include <ansi.h>

inherit NPC;

int ask_ziying(object me);

void create()
{
	set_name("̫���Ͼ�",({"taishang laojun","laojun","dao"}));
	set("gender", "����");
	set("age", 55);
	set("long", "		\n̫���Ͼ���\n");

	set("attitude", "peaceful");
	set("class", "taoist");
	set("combat_exp", 2000000);
	set("daoxing", 4000000);
	set("kee", 400);
	set("max_kee", 400);
	set("sen", 400);
	set("max_sen", 400);
	set("force", 400);
	set("max_force", 400);
	set("mana", 400);
	set("max_mana", 400);
	set("force_factor", 5);
	set("mana_factor", 10);

	set_skill("spells", 30);
	set_skill("dao", 30);
	set_skill("dodge", 60);
	set_skill("parry", 40);
	set_skill("unarmed", 30);

	set("inquiry", ([
		"ziying-sword"	:(: ask_ziying :),
		"��۫��"	:(: ask_ziying :),
		"here"	 : "������Ƕ��ʹ������������ʲô��",
	]));

	setup();
	carry_object("/d/lingtai/obj/cloth")->wear();
}


void init()
{
	object who;

	::init();
	if( interactive(who = this_player()) && !is_fighting() ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
}


void greeting(object who)
{
	object me = this_object();
	if (who->query("dntg/laojunlu")=="allow")
	{
		me->command("kick");
	who->set("dntg/laojunlu","allow");
		me->command("chat ���²��ã�"HIR+who->query("name")+HIC" �Ӱ���¯���ӳ����ˡ�������");
		remove_call_out("leave_laojunlu");
		call_out("leave_laojunlu", 1, who);	
	} 
}

int leave_laojunlu(object who)
{
	who = this_player();
	message("channel:rumor", HIC"��ҥ������"HIR+who->query("name")+"һ���߷��Ͼ�¯,ŭ��ֱ������������� \n"NOR, users());
	who->command("chat [1;31m����϶�����ţ��������ɱ��������������ǻ���ı���������[0m");
	who->move("/d/dntg/sky/tongmingdian");
}

int ask_ziying(object me)	
{
	me=this_player();
	if( me->query_temp("ask_ziying") == "tang1" ) 
	{
		command("consider");
		command("say �㸩��������");
		command("say ��˵������ׯ�ۺ�԰����Ϭţ����������Ƚ����������ȥ������");
		command("say �ϵ�һ��Ϊ�ˣ��Ἲ�����С���ø����ˣ��ѷ��������Լ���");
		me->set_temp("ask_ziying","laojun1");
		return 1;
	}
	else if( me->query_temp("ask_ziying") == "tieguaili" ) 
	{
		command("say ����ȴ��£���");
		message_vision("$N��ָһ��.....\n", this_object());
		message_vision("$N����ž��ɿ���Լ����������ƣ����������˻���Ϊʲô������ĵ���!\n", this_object());
		message_vision("��$N˵�����϶����ڻʹ�!\n", me);
		me->set_temp("ask_ziying","laojun2");
		return 1;
	}
	command("say ���������");
	message_vision ("��̫����Щ��������.\n",me);
	command("say ���ɻ������");
	me->set("enter", 1);
	return ("��ξͶ���л�����ˡ�����\n");
}
