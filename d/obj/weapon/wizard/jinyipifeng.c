// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
	set_name(HIY"不死鸟羽披风"NOR, ({"busi pifeng", "pifeng", "cloth" }));
	set_weight(4500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "一件用凤凰鸟羽精制而成的披风。\n");
		set("material", "crimsonsteel");
		set("unit", "件");
		set("value", 0);
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 5);
		set("armor_prop/spells", 10);
	}
	setup();
}


