// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"五彩天衣"NOR, ({"tian yi", "color cloth", "tianyi" }) );
	set("long", "此乃王母寿辰,织女用七彩云霞特别织就的天衣，触手轻似无物。\n");
	set_weight(0);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 40);
		set("armor_prop/dodge", 50);
		set("replace_file", "/d/obj/cloth/xianyi");
		set("armor_prop/personality", 10);
		set("value", 50000);
		set("female_only", 1);
	}
    set("no_sell", 1);
    set("no_drop", 1);
    set("no_put", 1);
	set("is_monitored",1);
	setup();
}

void init()
{
	cloth::init();
	unique::init();
}
