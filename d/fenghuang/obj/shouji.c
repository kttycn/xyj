inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"手机"NOR, ({"shou ji","ji"}));
	set_weight(500);
	set("unit", "台");
	set("value",200);
	set("long", "这就是人们俗称大哥大的破玩意。\n");
	set("no_sell", 1);
	setup();
}
int query_autoload() { return 1; }

