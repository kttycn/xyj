inherit ITEM;
#include "task.h"

void create()
{
	set_name("凤尾箭翎", ({"fengwei jianling", "jianling"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这就是当初后裔射日时剩下的一个凤尾箭翎。\n");
		set("unit", "支");
		set("owner_name","后羿");
		set("owner_id","hou yi");
	}
}
