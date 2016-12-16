//EDIT BYE LUCAS
inherit NPC;

void create()
{
	set_name("����", ({ "yuan long", "long"}));
	set("title", "��ˮ����");	 
	set("long", "һλ���Ž�ף�����ֱ޵�������\n");
	set("gender", "����");
	set("age", 50); 
	set("attitude", "heroism");
	set("per", 10);
	set("max_kee", 2500);
	set("max_gin", 1000);
	set("max_sen", 2000);
	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 100);
	set("max_mana", 3000);
	set("mana", 6000);
	set("mana_factor", 180);
	set("combat_exp", 2500000);
	set_skill("spells", 180);
	set_skill("seashentong", 180);
	set_skill("unarmed", 150);
	set_skill("mace", 150);
	set_skill("dragonfight", 150);
	set_skill("dodge", 160);
	set_skill("dragon-steps", 160);
	set_skill("wusi-mace", 170);
	set_skill("parry", 160);
	set_skill("force", 150);
	set_skill("dragonforce", 150);
	map_skill("spells", "seashentong");
	map_skill("unarmed", "dragonfight");
	map_skill("dodge", "dragon-steps");
	map_skill("force", "dragonforce");
	map_skill("mace", "wusi-mace");
	set("chat_msg_combat", ({
		(: cast_spell, "freez" :),
	}) );

	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
	carry_object("/d/obj/weapon/mace/copperjian.c")->wield();
}

int accept_fight (object ob)
{
	ob->apply_condition ("killer",100);
	kill_ob (ob);
	return 1;
}

void kill_ob (object ob)
{
	set_temp("no_return",1);
	set_temp("my_killer",ob);
	::kill_ob(ob);
}

void unconcious()
{
	object ob = query_temp("my_killer");
	object me = this_object();

	if (ob)
	{
		ob->set_temp("killlong",1);
		call_out ("aoshun_appearing",1,ob);
	}
	message_vision ("\n$N�ҽ�һ�������ڵ��ϣ�����ԭ�Σ�ԭ����һ������������\n",me);
	message_vision ("Ħ�����һ�������󣬸��һ�ȥ��������˵�깰��Ϊ��Ѻ��������ˮ·�ع�������\n\n",me);
	load_object("/obj/empty");
	me->move("/obj/empty");
	call_out ("destruct_me",3,me);
}

void aoshun_appearing (object who)
{
	object aoshun = new ("/d/qujing/xihai/npc/aoshun");

	aoshun->announce_success (who);
	destruct (aoshun); 
}

void destruct_me(object me)
{
	destruct(me);
}

void die()
{
	unconcious();
}
