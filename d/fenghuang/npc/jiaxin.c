inherit F_VENDOR_SALE;

void create()
{
	set_name("ۣо", ({ "jia xin", "jia" }));
	set("title", "�ӻ����ϰ�");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long",
		"ۣ�ϰ������������ķ�����ˣ����˼�ʮ���С������\n");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 40000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"beixin" : "/d/fenghuang/obj/beixin",
		"toukui" : "/d/fenghuang/obj/toukui",
		"cycle" : "/d/fenghuang/obj/cycle",
		"shield" : "/d/fenghuang/obj/shield",
		"pixue" : "/d/fenghuang/obj/pixue",
	]));

	setup();
	carry_object("/d/obj/cloth/cloth")->wear();
}

void init()
{
        add_action("do_vendor_list", "list");
}
