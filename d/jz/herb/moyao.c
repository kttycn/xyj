// moyao.c

#include "herb.h"

void create()
{
	set_name(WHT "ûҩ" NOR, ({ "moyao", "herb_moyao" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 300);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
