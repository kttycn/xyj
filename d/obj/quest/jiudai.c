inherit ITEM;
#include "task.h"

void create()
{
	set_name("酒袋", ({"jiudai" }));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "元先生喝酒用的东西。\n");
		set("unit", "个");
		set("owner_name","元先生");
		set("owner_id","yuan xiansheng");
	}
}
