inherit ITEM;
#include "task.h"

void create()
{
	set_name("轮回棒", ({"lunhui bang", "bang"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "轮回司主「鬼王」王方平的轮回棒\n");
		set("unit", "条");
		set("owner_name","王方平");
		set("owner_id","wang fangping");
	}
}
