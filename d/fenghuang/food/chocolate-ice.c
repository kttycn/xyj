// chocolate-ice.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ɿ����µ�", ({"chocolate-ice", "chocolate"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ɿ����ɷֵı���ܡ�\n");
		set("unit", "��");
		set("value", 1000);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
