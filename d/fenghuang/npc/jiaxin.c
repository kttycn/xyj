inherit F_VENDOR_SALE;

void create()
{
	set_name("郏芯", ({ "jia xin", "jia" }));
	set("title", "杂货铺老板");
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 35);
	set("long",
		"郏老板是土生土长的凤凰星人，做了几十年的小买卖。\n");
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
