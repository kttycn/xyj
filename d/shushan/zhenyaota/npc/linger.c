inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("�����", ({ "zhao linger", "linger"}));
	set("title","");
	set("long", "�������Ů��֮�󣬵�Ȼ�ǰ����ߡ�\n");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("str", 30);
	set("int", 40);
	set("spi", 50);
	set("per", 40);
	set("class","xian");
	
	set("kee", 2000);
	set("max_kee", 2000);
	set("sen", 3000);
	set("max_sen", 3000);
	set("force", 4000);
	set("max_force", 2000);
	set("mana", 6000);
	set("max_mana", 3000);
	set("force_factor", 60);
	set("mana_factor", 100);

	set("combat_exp", 1500000);
	set("daoxing", 2000000);

	set_skill("unarmed", 140);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("spells",200);
	set("inquiry", ([
		"����ң" : "���ܴ���ȥ����ң����𣿣�\n",
	]));
	setup();

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/xiuhuaxie")->wear();
}

void init()
{
	add_action("do_daying", "daying");
}

int do_daying(string arg)
{
	object who = this_player();
	object me = this_object();
	if(who->query("zhanyi/zhenyaota")) { 
		command("say ��Ҫ���Ҽ�����?");
	}
	else 
	{ 
		if(me->query_temp("help_offer") != 0)
			return notify_fail("���������"+who->query("name")+"�Ѿ���Ӧ���ˣ�\n��");
		message_vision("$N��Ӧ�������\n", who);
		command("jump "+who->query("id"));
		command("kiss "+who->query("id"));
		command("follow "+who->query("id"));
		command("say "+"�ǾͰ���������\n");
		me->set_temp("help_offer",who->query("name"));
		who->set_temp("shushan/linger_daying",1);
		who->set("shushan/yue_perform",1);
	}
	return 1;
}