inherit ITEM;
#include "task.h"

void create()
{
	set_name("人皮账本", ({"renpi zhangben", "zhangben"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "田鼠精用来记帐的小本子。\n");
		set("unit", "个");
		set("owner_name","田鼠精");
		set("owner_id","tian shu");
	}
}
