inherit ITEM;
#include "task.h"

void create()
{
	set_name("风灵珠", ({"feng lingzhu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "传说中的五行宝珠之一，佩之可避风吹，并可发出风系法术。\n为祈雨所必需之物。\n");
		set("unit", "只");
		set("owner_name","观音菩萨");
		set("owner_id","guanyin pusa");
	}
}
