// sumu.c

#include "herb.h"

void create()
{
	set_name(WHT "��ľ" NOR, ({ "su mu", "herb_sumu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 5000);
        	set("weight", 60);
set("base_unit","��");
	}
	setup();
}
