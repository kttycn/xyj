// shenglg.c

#include "herb.h"

void create()
{
	set_name(CYN "������" NOR, ({ "shenglong gu", "herb_slg" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 4000);
        	set("weight", 120);
set("base_unit","��");
	}
	setup();
}
