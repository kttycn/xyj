// chenpi.c

#include "herb.h"

void create()
{
	set_name(YEL "��Ƥ" NOR, ({ "chenpi", "herb_chenpi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 10);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
