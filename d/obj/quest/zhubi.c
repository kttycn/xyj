inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
	set_name("÷Ï± ", ({"Zhu bi", "bi"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "’‚ø… «±¶±¥∞°°£\n");
		set("unit", "÷ß");
		set("owner_name",HIW"¥ﬁÁÂ"NOR);
		set("owner_id","cui jue");
	}
}
