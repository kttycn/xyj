#include <armor.h>
#include <ansi.h>
inherit BOOTS; 
void create()
{
	set_name(HIB "兽皮靴"NOR, ({ "boots", "pi xue", "xue" }) );
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "leather");
		set("unit", "双");
		set("long", "这是一双用上好兽皮作的皮靴，据说由皇族进口。\n");
		set("value", 40000);
		set("armor_prop/dodge", 5);
	}
	setup();
}

