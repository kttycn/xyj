inherit ITEM;
#include "task.h"
void create()
{
	set_name("柳树枝", ({"liushu zhi", "shizhi"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这可是具有法力的树枝!\n");
		set("unit", "条");
		set("owner_name","观音菩萨");
		set("owner_id","guanyin pusa");
	}
}
