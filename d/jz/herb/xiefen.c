// xiefen.c

#include "herb.h"

void create()
{
	set_name(HIM "Ы��" NOR, ({ "xiefen", "herb_xiefen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 500);
        	set("weight", 35);
set("base_unit","��");
	}
	setup();
}
