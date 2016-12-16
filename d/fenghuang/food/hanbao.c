// hanbao.c 包子

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("汉堡包", ({"hanbaobao", "hanbao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个香喷喷的夹心汉堡包。\n");
		set("unit", "个");
		set("value", 100);
		set("food_remaining", 5);
		set("food_supply", 50);
	}
}
