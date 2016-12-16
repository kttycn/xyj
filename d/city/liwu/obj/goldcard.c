
#include <ansi.h>

inherit F_AUTOLOAD;  
inherit ITEM;

void create()
{
    set_name(HIY"��"NOR, ({ "gold card", "card", "ka"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 10000);
		set("no_drop", "������������Ү��������ӵ���\n");
        set("no_give", "������������Ү��������������\n");
		set("material", "steel");
	}
	set("is_monitored",1);
	setup();
}

void init()
{
	add_action("do_look","look");
}

int do_look(string arg)  
{
	object me = this_player(), card;
	int money;

	if(arg!="card"&&arg!="gold card")
		return 0;
	tell_object(me,"���Ѹ���Ϊ���ÿ���ԭ�����е�\n"
		+MONEY_D->price_str(me->query("card_money"))+"ת���µ����ÿ��У��ۺ�"
		+MONEY_D->price_str(me->query("card_money")/10)+"��\n");

	if(me->query("card_money"))
		if (me->add("balance",me->query("card_money")/10))
			me->delete("card_money");
	
	card = new("/obj/money/account");
	card->move(me);
	destruct(this_object());
	return 1;
}

int query_autoload() { return 1; }
