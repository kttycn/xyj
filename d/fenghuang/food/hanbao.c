// hanbao.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"hanbaobao", "hanbao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������ļ��ĺ�������\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
