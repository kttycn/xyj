// coin.c

inherit MONEY;

void create()
{
	set_name("Ǯ", ({"coin", "coins", "coin_money" }));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "coin");
		set("long", "������ͨ�е�λ��С�Ļ��ң�ԼҪһ����Ǯ��ֵ��һ�����ӡ�\n");
		set("unit", "Щ");
		set("base_value", 1);
		set("base_unit", "��");
		set("base_weight", 1);
	}
	set_amount(1);
}
