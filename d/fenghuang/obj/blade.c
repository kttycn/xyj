// ZHANGM 1999/12/18 
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(RED "暗月刃"NOR, ({"dao", "blade"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄暗红色的月形弯刀，刀身透出一股杀气。\n");
		set("value", 500);
		set("material", "steel");
		set("wield_msg", HIR "只见红光一闪，$N的手中多了一柄暗红色的$n。\n"NOR);
		set("unwield_msg", HIY "$N将手一扬，$n已无踪影。\n"NOR);
	}
	init_blade(40);
	setup();
}

