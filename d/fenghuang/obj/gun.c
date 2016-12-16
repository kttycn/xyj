#include <weapon.h>

inherit GUN;

void create()
{
	set_name("雷射枪", ({"gun" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把雷射枪，似乎威力巨大。\n");
		set("value", 200);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_gun(20);
	setup();
}


