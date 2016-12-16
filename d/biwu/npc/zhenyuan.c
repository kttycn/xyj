#define DEBUG 0

inherit NPC;

void create()
{
	set_name("��Ԫ����", ({"zhenyuan daxian", "zhenyuan", "daxian"}));
	set("title", "��ׯ�۹���");
	set("gender", "����" );
	set("age", 65);
	set("per", 24);
	set("str", 30);
	set("long", "���α����磬���������С���һλ����֮�棡\n");
	set("class", "xian");
	set("combat_exp", 5600000);
	set("daoxing", 10000000);

	set("attitude", "peaceful");
	set("rank_info/respect", "����");
	set_skill("unarmed", 180);
	set_skill("wuxing-quan", 200);
	set_skill("dodge", 180);
	set_skill("baguazhen", 160);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("sanqing-jian", 190);
	set_skill("xiaofeng-sword", 190);
	set_skill("staff", 160);
	set_skill("fumo-zhang", 190);
	set_skill("hammer", 160);
	set_skill("kaishan-chui", 190);
	set_skill("blade", 160);
	set_skill("yange-blade", 190);
	set_skill("force", 180);	
	set_skill("zhenyuan-force", 180);
	set_skill("literate", 180);
	set_skill("spells", 200);
	set_skill("taiyi", 200);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "xiaofeng-sword");
	map_skill("parry", "xiaofeng-sword");
	map_skill("dodge", "baguazhen");
	map_skill("staff", "fumo-zhang");
	map_skill("blade", "yange-blade");
	map_skill("hammer", "kaishan-chui");

	set("max_kee", 4500);
	set("max_sen", 4500);
	set("force", 5000);
	set("max_force", 2500);
	set("mana", 7000);
	set("max_mana", 3500);	
	set("force_factor", 200);
	set("mana_factor", 200);

	set("spell_qiankun_on", 1); //to use cast qiankun, must set this.
	set("chat_chance_combat", 90);
	set("chat_msg_combat", 
	({
		(: cast_spell, "zhenhuo" :),
//		(: cast_spell, "qiankun" :),
		(: perform_action, "sword", "tiandi" :),
	}) );
	create_family("��ׯ��", 1, "��ʦ");

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/ruler")->wield();
}

