inherit ITEM;
#include "task.h"

void create()
{
	set_name("神枪", ({"shen spear", "spear"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是罗成的惯用兵器。\n");
		set("unit", "柄");
		set("owner_name", "罗成");
		set("owner_id", "luo cheng");
	}
}

