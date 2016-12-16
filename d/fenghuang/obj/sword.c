// ZHANGM 1999/12/18 
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIC "天驱"NOR, ({"sword", "jian"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把银白色的光剑，剑身透出隐隐寒气。\n");
		set("value", 5000);
		set("material", "steel");
		set("wield_msg", HIW "只见白光一闪，$N的手中多了一把银白色的$n。\n"NOR);
		set("unwield_msg", HIW "$N将手一扬，$n已无踪影。\n"NOR);
	}
	init_sword(40);
	setup();
}

