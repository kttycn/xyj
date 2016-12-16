// peach.c

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("松子", ({"song zi"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个干巴巴的松子。\n");
		set("unit", "个");
		set("value", 0);
		set("food_remaining", 2);
		set("food_supply", 10);
	}
}
