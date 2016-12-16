#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
	set_name(MAG"魅影神靴"NOR, ({"meiying shenxuan", "meiying", "shoes" }) );
	set("long", "不知用何物做成，通体呈暗紫色，透出一股神秘的气息。\n");
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "双");
		set("material", "boots");
		set("armor_prop/armor", 32);
		set("armor_prop/dodge", 26);
		set("armor_prop/personality", 2);
		set("value", 0);
	}
	setup();
}

