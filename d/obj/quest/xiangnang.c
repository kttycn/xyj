inherit ITEM;
#include "task.h"

void create()
{
	set_name("香囊", ({"xiang nang" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "百花仙子平日用的香囊。\n");
		set("unit", "个");
		set("owner_name","百花仙子");
		set("owner_id","baihua xianzi");
	}
}
