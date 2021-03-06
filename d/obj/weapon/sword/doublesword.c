#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(MAG"紫"CYN"青"NOR"双剑"NOR, ({"ziqing shuangsword", "sword" }));
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把淡青色的的长剑和一把淡紫色的长剑，隐含着一种神秘的力量。\n");
		set("no_sell", 1);
		set("no_put", 1);
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/changjian");
		set("material", "crimsonsteel");
		set("wield_msg", "两道眩目的 "MAG"紫 "CYN"青 "NOR"剑光闪过,双剑和体,你一握在手,不由豪气顿生。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
		set("weapon_prop/int", 9);
		set("weapon_prop/per", 4);
	}
	init_sword(180);
	set("is_monitored",1);
	setup();
}
