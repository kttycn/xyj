inherit F_VENDOR_SALE;

void create()
{
	set_name("����ʦ", ({ "zhujian shi", "shi" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

	set("gender", "����" );
	set("age", 33);
	set("long", "��˵��ԭ���Ǵ������ն�����ʦ��Ϊ����ǽ�ʿ���������������֪��ô�����ˡ�\n");

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
	command("say ��λ" + RANK_D->query_respect(ob) +"��������");
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
message_vision("$N����$nһ������ĸֵ���\n", this_object(), who);
	if( what=="sword" )
message_vision("$N����$nһ�Ѱ׹������Ĺ⽣��\n", this_object(), who);
}

*/