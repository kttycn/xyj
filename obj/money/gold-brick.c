#include <ansi.h>
inherit MONEY;
//inherit ITEM;
void create()
{
	set_name(HIY"月影金砖"NOR, ({"gold-zhuan", "brick", "gold-brick"}));
	set_weight(6400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jinkuai");
		set("long", HIY"一块月影奇缘的金砖，正面是石头抱剑卓立风中的全身像，反面是全体巫师的全家福。\n"NOR);
		set("unit", "堆");
		set("base_value", 10000000000);
		set("base_unit", "块");
		set("base_weight", 24);
	}
	set_amount(1);
}

