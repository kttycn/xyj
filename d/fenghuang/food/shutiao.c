// shutiao.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ը����", ({"zhashutiao", "shutiao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ո�ը�õ�������\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
