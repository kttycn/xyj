inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("狗不理", ({"goubuli baozi", "baozi", "dumpling"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "正宗天津狗不理包子。\n");
		set("unit", "个");
		set("value", 500);
		set("food_remaining", 3);
		set("food_supply", 20);
	}
}
