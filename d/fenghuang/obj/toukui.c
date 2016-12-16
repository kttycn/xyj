#include <armor.h> 
#include <ansi.h>
inherit HEAD;
void create()
{
	set_name(HIW "¹â×Ó¿ø"NOR, ({ "helmet", "toukui" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "steel");
		set("unit", "¶¥");
		set("value", 90000);
		set("armor_prop/armor", 10);
		set("armor_prop/dodge", 1);
	}
	setup();
}

