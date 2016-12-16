// hefan.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("盒饭", ({"hefan", "fan"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个三荤一素的盒饭。\n");
		set("unit", "个");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}

