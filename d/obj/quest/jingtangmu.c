inherit ITEM;
#include "task.h"

void create()
{
	set_name("惊堂木" , ({"jingtang mu" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "说书用的家什。\n");
		set("unit", "个");
		set("owner_name","说书老");
		set("owner_id","shuoshu lao");
	}
}
