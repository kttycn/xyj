// chocolate-ice.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("巧克力新地", ({"chocolate-ice", "chocolate"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个含有巧克力成分的冰淇淋。\n");
		set("unit", "个");
		set("value", 1000);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
