// seven_belt.c

#include <ansi.h>

inherit F_UNIQUE;
inherit EQUIP;

void create()
{
	set_name( HIY "七彩宝石指环" NOR, ({ "seven belt", "belt" }) );
    set("long", "这是一个镶着一颗通体由不断变化的似七条异色飞凤般游动的指环。\n");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 27000);
		set("material", "cloth");
		set("no_sell", 1);
		set("no_put", 1);
	    set("no_drop", 1);
		set("replace_file", "/d/obj/misc/hualan");
		set("armor_type", "waist");
		set("armor_prop/armor", 50);
		set("armor_prop/dodge", 20);
		set("armor_prop/intelligence",5);
		set("armor_prop/personality",5);
	}
	set("is_monitored",1);
	setup();
}

