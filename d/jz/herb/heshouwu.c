// heshouwu.c

#include "herb.h"

void create()
{
	set_name(HIW "������" NOR, ({ "shouwu", "herb_heshouwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 10000);
        	set("weight", 85);
set("base_unit","��");
	}
	setup();
}
