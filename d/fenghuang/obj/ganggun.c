#include <weapon.h>

inherit STICK;

void create()
{
	set_name("钢棍", ({ "ganggun", "gun" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根精钢制成的棍子，似乎威力不大。\n");
		set("value", 100);
		set("material", "iron");
		set("wield_msg", "$N拿出一根$n，握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_stick(20);
	setup();
}

