// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
	set_name("卖花女", ({"maihua nv","nv","girl"}));
	set("gender", "女性");
	set("combat_exp", 1000);
	set("age", 16);
	set("per", 23);
	set("attitude", "friendly");
	set("shen_type", 1);
	set_skill("unarmed", 10);
	set("vendor_goods", ([
		"flower": "/d/obj/flower/rose",
		"hualan": "d/xuyi/obj/hualan",
		"rose": "/d/obj/flower/hua",
		"rose999": "/d/obj/flower/rose999",
	]) );
	setup();

	carry_object("/d/obj/cloth/skirt")->wear();
	carry_object("/d/obj/cloth/shoes")->wear();
//	add_money("silver", 1);
}

void init()
{
	object ob;

	::init();
	add_action("do_vendor_list", "list");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ) return;
	switch( random(3) ) {  // 1/3 chance to greet.
		case 0 : command("say 现在的花可真是少呀！"); break;
	}
}

