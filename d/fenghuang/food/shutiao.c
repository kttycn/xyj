// shutiao.c 

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("炸薯条", ({"zhashutiao", "shutiao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一包刚刚炸好的薯条。\n");
		set("unit", "包");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
