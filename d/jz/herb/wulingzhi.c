// wulingzhi.c

#include "herb.h"

void create()
{
	set_name(MAG "����֬" NOR, ({ "wu lingzhi", "herb_wulingzhi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 5000);
        	set("weight", 100);
set("base_unit","��");
	}
	setup();
}
