// taoxian.c

#include "herb.h"

void create()
{
	set_name(MAG "����" NOR, ({ "tao xian", "herb_taoxian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 5000);
        	set("weight", 40);
set("base_unit","��");
	}
	setup();
}
