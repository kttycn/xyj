inherit ITEM;
#include "task.h"

void create()
{
	set_name("土灵珠", ({"tu lingzhu"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long","传说中的五行宝珠之一，佩之可避石砸，并可发出土系法术。\n为祈雨所必需之物。");
		set("owner_name","观音菩萨");
		set("owner_id","guanyin pusa");
	}
	setup();
}
