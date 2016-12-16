// thousand.c

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(HIR"一百元月影币"NOR, ({"renminbi", "rmb money"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "rmb");
		set("long", "一张面值为一百元的月影币，价值十两黄金。\n");
		set("unit", "张");
		set("base_value", 100000);
		set("base_unit", "张");
		set("base_weight", 3);
	}
	set_amount(1);
}

