#include <ansi.h>
#include <armor.h>
inherit FINGER;

void create()
{
	set_name( HIW"冰玉戒指"NOR, ({ "ice ring", "ring" }) );
	set_weight(60);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 0);
    	set("long", "这个戒指是天然冰玉形成，通体有一根如血的红丝如龙般的游动。传说戴上\n它有避邪的功效。\n");
		set("material", "gold");
		set("armor_prop/unarmed", 2);
		set("armor_prop/armor", 1);
		set("armor_prop/spells", 2);
        set("wear_msg", "$N将$n拿出戴在右手无名指上。\n");
	}
	setup();
}
