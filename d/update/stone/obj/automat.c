#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
	set_name("����", ({ "icebox", "bingxiang", "box" }) );
//	set("gender", "��" );
//	set("age", 22);
//	set("per", 30);
//	set("combat_exp", 10000);

	set("vendor_goods", ([
		"xuejia": "/d/fenghuang/food/yan",
		"shutiao": "/d/fenghuang/food/shutiao",
		"binjilin1" : "/d/fenghuang/food/banana-ice",
		"jiuhu": "/d/fenghuang/food/jiuhu",
		"hefan": "/d/fenghuang/food/hefan",
		"hanbao": "/d/fenghuang/food/hanbao",
		"binjilin2" : "/d/fenghuang/food/chocolate-ice",
		"chengzhi" : "/d/fenghuang/food/chengzhi",
		"pepsi" : "/d/fenghuang/food/pepsi",
	]) );

//	set("attitude", "friendly");
//	set("rank_info/respect", "������");
	setup();
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
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "���䷢��������Ů��˵������λ" + RANK_D->query_respect(ob)
				+ "�������Ͷ�����Զ��ۻ������õ�����Ҫ����Ʒ��\n");
			break;
		case 1:
			say( "���䷢��������Ů��˵������λ" + RANK_D->query_respect(ob)
				+ "��лл���١�\n");
			break;
		case 2:
			say( "���䷢��������Ů��˵������λ" + RANK_D->query_respect(ob)
				+ "������Բ鿴(list)�ۻ����е���Ʒ��\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	int value;

	if (ob->query("money_id") && (value=ob->value()) >= 10000) 
	{
		tell_object(who, "������˵����лл���٣�����¥ЪϢ��\n");
		who->set_temp("rent_paid",1);
		take_money(value, 10000);
		return 1;
	}

	return 0;
}
