// niuqi.c

#include "herb.h"

void create()
{
	set_name(CYN "ţϥ" NOR, ({ "niu xi", "herb_niuxi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 2000);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
