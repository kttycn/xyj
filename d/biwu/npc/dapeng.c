// dapeng.c...weiqi, 97.09.27.

inherit NPC;

void create()
{
	set_name("��������", ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
	set("title", "ѩɽ֮��");
	set("gender", "����" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "��λ����������ȷ����������˵��������������Ҳ�е����ݹ�ϵ��\n���������ġ��˾ˡ������������ֿ�ȸ���������ˣ�ȴҲ�������࣬\n��������֮�ʸ����Ž��������ƽ������ľ��Ǻ��С�\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	set("rank_info/respect", "����");
	set_skill("unarmed", 150);
	set_skill("cuixin-zhang", 150);
	set_skill("dodge", 200);
	set_skill("xiaoyaoyou", 200);
	set_skill("parry", 170);
	set_skill("sword", 180);
	set_skill("bainiao-jian", 180);
	set_skill("blade", 180);
	set_skill("bingpo-blade", 180);
	set_skill("throwing", 180);
	set_skill("force", 180);   
	set_skill("ningxue-force", 180);
	set_skill("literate", 150);
	set_skill("spells", 160);
	set_skill("dengxian-dafa", 160);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxue-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: cast_spell, "juanbi" :),
		(: cast_spell, "tuntian" :),
		(: perform_action, "blade", "yaowu" :)
	}) );
	create_family("��ѩɽ", 1, "��ʦ");

	setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

