#include <ansi.h>
#include <armor.h> 
inherit SHIELD; 
void create()
{
	set_name(HIW "������"NOR, ({ "shield", "dun" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "��");
		set("value", 120000);
		set("armor_prop/armor", 10);
		set("armor_prop/defense", 5);
	}
	setup();
}

