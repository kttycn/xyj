#include <weapon.h>
#include <ansi.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
	set_name(MAG"紫"CYN"青"NOR"双剑"NOR, ({"ziqing shuangsword", "sword","shuangsword" }));
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把淡青色的的古剑和一把淡紫色的古剑，隐含着一种神秘的力量。\n");
		set("no_sell", 1);
		set("no_put", 1);
		set("value", 30000);
		set("replace_file", "/d/obj/weapon/sword/changjian");
		set("material", "crimsonsteel");
		set("wield_msg", "两道眩目的 "MAG"紫 "CYN"青 "NOR"剑光闪过,双剑和体,你一握在手,不由豪气顿生。\n");
		set("unwield_msg", "一道眩目的"MAG"紫电"CYN"青光"NOR"一闪，$N手中的$n自行飞入剑鞘中。\n");
		set("weapon_prop/courage", 5);
		set("weapon_prop/composure", 5);
	}
	init_sword(180);
	set("is_monitored",1);
	setup();
}
