#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(MAG"月影金币"NOR, ({"gold-coin", "ingot", "gold-coin_money"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "jinbi");
		set("long", HIY"一枚月影奇缘的硬币，正面是菲飞负剑卓立风中的全身像，反面是全体巫师的全家福。\n"NOR);
		set("unit", "堆");
		set("base_value", 1000000);
		set("base_unit", "枚");
		set("base_weight", 3);
	}
	set_amount(1);
}

