// tugou.c

#include "herb.h"

void create()
{
	set_name(YEL "����" NOR, ({ "tu gou", "herb_tugou" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 900);
        	set("weight", 80);
set("base_unit","��");
	}
	setup();
}
