#include <ansi.h>
inherit MONEY;
//inherit ITEM;
void create()
{
	set_name(HIY"月影金条"NOR, ({"gold-tiao", "bar", "gold-bar"}));
	set_weight(3200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jintiao");
		set("long", HIY"一条月影奇缘的金条，正面是石头抱剑卓立风中的全身像，反面是全体巫师的全家福。\n"NOR);
		set("unit", "条");
		set("base_value", 100000000);
		set("base_unit", "块");
		set("base_weight", 12);
	}
	set_amount(1);
}

