#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
	set_name(HIW"��ɫ��ѥ"NOR, ({ "shoes" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("material", "boots");
		set("armor_prop/armor", 15);
		set("armor_prop/dodge", 5);
		set("armor_prop/personality", 10);
	}
	setup();
}
