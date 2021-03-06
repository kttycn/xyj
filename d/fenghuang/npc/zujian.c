inherit F_VENDOR_SALE;

void create()
{
	set_name("铸剑师", ({ "zhujian shi", "shi" }));
	set("title", "武器铺老板");
	set("shen_type", 1);

	set("gender", "男性" );
	set("age", 33);
	set("long", "据说他原来是大宗主钦定铸剑师，为凤凰星将士铸造兵器，后来不知怎么隐退了。\n");

	set("combat_exp", 200000);
	set("attitude", "friendly");
	set("vendor_goods", ([
		"blade" : "/d/fenghuang/obj/blade",
		"sword" : "/d/fenghuang/obj/sword",
		"ji" : "/d/obj/weapon/halberd/sanchaji",
		"gun" : "/d/fenghuang/obj/gun",
		"stick" : "/d/fenghuang/obj/ganggun",
		"dagger" : "/d/fenghuang/obj/bishou",
	]));

	setup();
	carry_object("/d/obj/cloth/cloth")->wear();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
	command("say 这位" + RANK_D->query_respect(ob) +"请进请进。");
}
/*
void init()
{
	add_action("do_buy", "buy");
}


int buy_object(object who, string what)
{
	if( what=="blade" ) return 300;
	if( what=="sword" ) return 700;
	return 0;
}

void compelete_trade(object who, string what)
{
	object ob;

	if( what=="blade" )  ob = new("/d/fenghuang/obj/blade");
	if( what=="sword" )  ob = new("/d/fenghuang/obj/sword");
	ob->move(who);
	if( what=="blade" )
message_vision("$N交给$n一柄沈甸甸的钢刀。\n", this_object(), who);
	if( what=="sword" )
message_vision("$N交给$n一把白光闪闪的光剑。\n", this_object(), who);
}

*/