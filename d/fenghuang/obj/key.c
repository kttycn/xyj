inherit ITEM;
#include <ansi.h>;
void create()
{
	set_name(HIC "钥匙"NOR, ({"phoenix key", "key"}));
	set("long",
		"这是一把很金光闪闪的钥匙。\n");
	set("unit", "把");
	set("weight", 10);
}

