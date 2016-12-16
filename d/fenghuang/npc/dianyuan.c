inherit F_VENDOR_SALE;

void create()
{
	set_name("��Ա", ({ "dian yuan", "yuan" }));
	set("title", "����");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 25);
	set("long",
		"���Ǹ����˴򹤵�С���ӡ�\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"shouji" : "/d/fenghuang/obj/shouji",
		"xunhuji" : "/d/fenghuang/obj/xunhuji",
		"jieshouqi" : "/d/fenghuang/obj/jieshouqi",
	]));
	
	setup();
	carry_object("/d/obj/cloth/cloth")->wear();
}

void init()
{
	add_action("do_vendor_list", "list");
}

