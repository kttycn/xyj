inherit ITEM;
#include "task.h"

void create()
{
	set_name("圣灵珠", ({"sheng lingzhu"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long","天地初开时，清者归于上，浊者归于下；有一种半清半浊归于中，是为此宝！\n因此五行皆为其子。\n");
		set("owner_name","观音菩萨");
		set("owner_id","guanyin pusa");
	}
	setup();
}
