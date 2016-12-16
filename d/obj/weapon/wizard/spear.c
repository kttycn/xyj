// jinqiang.c
// updated 5-30-97 pickle


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
	set_name(HIW "沥泉枪" NOR, ({ "liquan spear","qiang","spear" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
		set("value", 0);
		set("material", "gold");
		set("long", "相传此枪为神龙所化，通体银白无瑕。\n");
		set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
		set("unwield_msg", "$N将$n放入背囊中。\n");
	}
	init_spear(160);
	setup();
}

