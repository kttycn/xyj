// hefan.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�з�", ({"hefan", "fan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������һ�صĺз���\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}

