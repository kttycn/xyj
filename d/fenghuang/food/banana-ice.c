// banana-ice.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("香蕉新地", ({"banana-ice", "banana"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个以香蕉为主要成分的冰淇淋。\n");
		set("unit", "个");
		set("value", 800);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
