#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("��Ƥսѥ", ({ "elephant boots","boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("armor_prop/armor", 15);
		set("armor_prop/dodge", 5);
	}
	setup();
}
