// shengdi.c

#include "herb.h"

void create()
{
	set_name(WHT "����" NOR, ({ "shengdi", "herb_shengdi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 500);
        	set("weight", 60);
set("base_unit","��");
	}
	setup();
}
