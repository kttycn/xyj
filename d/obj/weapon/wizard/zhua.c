#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name("短铁爪", ({ "tie zhua", "zhua", "dagger" }) );
	init_dagger(25);
	set("unit", "根");
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 280);
	    set("long", "这个铁爪看起来就象一个鹰爪一般，在灵活多变上，却比鹰爪更适用。\n");
		set("material", "tron");
	}
	set("wield_msg","$N拿起$n握在手里。\n");
	init_dagger(155);
	setup();
}

