inherit NPC;
string avenge();

void create()
{
	set_name("����", ({ "qin qiong", "qin", "shubao", "qiong", "qin shubao", "master", "shifu" }));
	set("title", "����Ԫѫ");
	set("gender", "����");
	set("age", 43);
	set("str", 30);
	set("per", 26);
	set("int", 30);
	set("cor", 50);
	set("cps", 50);
	set("long", "���屦�Ǵ��ƹ���������������һλ�������佫��\n");
	set("combat_exp", 1200000);
	set_skill("literate", 120);
	set_skill("spear", 120);
	set_skill("force", 120);
	set_skill("dodge", 180);
	set_skill("parry", 150);
	set_skill("xuanyuan-archery",180);
	set_skill("mace", 200);
	set_skill("archery", 150);
	set_skill("wusi-mace", 180);
	set_skill("yanxing-steps", 150);
	set_skill("bawang-qiang", 100);
	set_skill("lengquan-force", 120);
	set_skill("unarmed", 160);
	set_skill("changquan", 120);
	map_skill("mace", "wusi-mace");
	map_skill("force", "lengquan-force");
	map_skill("unarmed", "changquan");
	map_skill("spear", "bawang-qiang");
	map_skill("archery", "xuanyuan-archery");
	map_skill("parry", "bawang-qiang");
	map_skill("dodge", "yanxing-steps");
	set("max_sen", 2800);
	set("max_kee", 4400);
	set("force", 2000);
	set("max_force", 1800);
	set("force_factor", 80);

	create_family("������", 2, "��");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "spear", "lianhuan" :),
		(: perform_action, "spear", "meihua" :),
		(: perform_action, "spear", "qiangjian" :),
		(: perform_action, "spear", "bugong" :)
	}) );
	create_family("������", 2, "��");

	setup();
	carry_object("/d/obj/weapon/spear/yinqiang")->wield();
	carry_object("/d/obj/armor/tiejia")->wear();
	carry_object("/d/obj/weapon/mace/copperjian");
}

