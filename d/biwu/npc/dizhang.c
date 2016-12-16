//puti.c
inherit NPC;

void create()
{
	set_name("�ز�������", ({"dizang pusa", "pusa"}));
	set("long", "�������񣬴�����磬һ���ྲ��
�������������ܵظ������¹��ĵز���������\n");
	set("gender", "����");
	set("class", "youling");
	set("age", 70);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 30);
	set("str", 30);
	set("int", 30+random(5));
	set("nkgain",790);
	set("max_kee", 3000);
	set("max_gin", 2500);
	set("max_sen", 2000);

	set("force", 5000);
	set("max_force", 2500);
	set("force_factor", 200);
	set("max_mana", 2500);
	set("mana", 5000);
	set("mana_factor", 200);

	set("combat_exp", 2000000);
	set("daoxing", 4000000);

	set_skill("stick", 180);
	set_skill("kusang-bang", 180);
	set_skill("unarmed", 180);
	set_skill("whip", 180);
	set_skill("hellfire-whip", 200);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("literate", 150);
	set_skill("spells", 200);
	set_skill("force", 180);
	set_skill("tonsillit", 150);
	set_skill("ghost-steps", 180);
	set_skill("gouhunshu", 180);
	set_skill("jinghun-zhang", 180);
	set_skill("zhuihun-sword", 180);
	set_skill("sword", 180);

	map_skill("force", "tonsillit");
	map_skill("unarmed", "jinghun-zhang");
	map_skill("dodge", "ghost-steps");
	map_skill("spells", "gouhunshu");
	map_skill("parry", "hellfire-whip");
	map_skill("whip", "hellfire-whip");
	map_skill("sword", "zhuihun-sword");
	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: exert_function, "powerup" :),
		(: exert_function, "sheqi" :),
		(: perform_action, "whip", "three" :),
		(: perform_action, "whip", "lunhui" :),
		(: cast_spell, "inferno" :),
		(: cast_spell, "hunfei" :)
	}) );
	set("nk_gain", 600);
	 
	set_temp("apply/armor", 50);
	set_temp("apply/dodge", 50);
	create_family("���޵ظ�", 1, "���");
	setup();
	
	carry_object("/d/obj/cloth/baipao")->wear();
	carry_object("/d/obj/weapon/whip/longsuo")->wield();
}

