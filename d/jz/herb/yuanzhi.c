// yuanzhi.c

#include "herb.h"

void create()
{
	set_name(HIB "Զ־" NOR, ({ "yuan zhi", "herb_yuanzhi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 3000);
        	set("weight", 75);
set("base_unit","��");
	}
	setup();
}
