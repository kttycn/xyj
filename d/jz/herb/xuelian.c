// xuelian.c

#include "herb.h"

void create()
{
	set_name(HIW "雪山雪莲" NOR, ({ "xueshan xuelian", "herb_xuelian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。只生长于大雪山绝峰极寒之处。\n");
		set("unit", "朵");
		set("value", 30000);
        	set("weight", 40);
set("base_unit","朵");
	}
	setup();
}
