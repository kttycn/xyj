inherit ITEM;
#include "task.h"

void create()
{
	set_name("一柱香", ({"yizhu xiang", "xiang"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "在商店里面很常见的一种香。\n");
		set("unit", "根");
		set("owner_name","烧香老太太");
		set("owner_id","lao taitai");
	}
}
