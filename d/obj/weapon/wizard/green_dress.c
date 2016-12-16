// green_dress.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIB "青衫" NOR, ({ "green dress", "dress" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 0);
	    set("long", "一件用情丝织就的长衫。\n");
		set("material", "cloth");
		set("armor_type", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/dodge", 10);
	}
}

