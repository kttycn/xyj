#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name( BLU "��Ƥ����"NOR, ({ "beixin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 80000);
		set("material", "leather");
		set("armor_prop/armor", 20);
	}
	setup();
}

