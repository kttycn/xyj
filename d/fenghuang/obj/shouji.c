inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIW"�ֻ�"NOR, ({"shou ji","ji"}));
	set_weight(500);
	set("unit", "̨");
	set("value",200);
	set("long", "����������׳ƴ���������⡣\n");
	set("no_sell", 1);
	setup();
}
int query_autoload() { return 1; }

