// guiwei.c

#include "herb.h"

void create()
{
	set_name(WHT "��β" NOR, ({ "gui wei", "herb_guiwei" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 3000);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
