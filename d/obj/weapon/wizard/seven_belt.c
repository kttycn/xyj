// seven_belt.c

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name( HIY "七彩宝石指环" NOR, ({ "seven belt", "belt" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 0);
		set("material", "cloth");
	    set("long", "这是一个镶着一颗通体由不断变化的似七条异色飞凤般游动的指环。\n");
		set("armor_type", "waist");
		set("armor_prop/armor", 50);
		set("armor_prop/dodge", 20);
		set("armor_prop/intelligence",15);
		set("armor_prop/personality",15);
	}
}

