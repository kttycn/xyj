// tianqi.c

#include "herb.h"

void create()
{
	set_name(WHT "����" NOR, ({ "tianqi", "herb_tianqi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 400);
        	set("weight", 55);
set("base_unit","��");
	}
	setup();
}
