// windspring.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name( CYN "风泉之剑" NOR, ({ "sword of windspring", "sword" }) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long",
			"这是步玄派历代相传的掌门信物，湛蓝色的剑身跟鹅黄色剑柄，使\n"
			"得风泉之剑成为具有「剑之王者」的美誉，除此之外，这把剑也是\n"
			"削铁如泥的利器。\n");
		set("value", 0);
		set("material", "sapphire");
		set("wield_msg", "$N「刷」地一声抽出一柄闪著寒光的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的剑鞘。\n");
		set("weapon_prop/courage", 15);
		set("weapon_prop/intelligence", 15);
		set("weapon_prop/personality", 15);
		set("rigidity", 40);
		set("replica_ob", "/obj/longsword");
	}

	init_sword(75);
	setup();
}

