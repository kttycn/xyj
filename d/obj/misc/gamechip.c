// gamechip.c                   
// ����

inherit MONEY;

void create()
{
	set_name("����", ({ "gambling chip", "chip", "game_money" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "���������ֳ�����ʹ�õĴ��ҡ�\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "ö");
		set("base_weight", 1);
	}
	set_amount(1);
}

