// lurong.c

#include "herb.h"

void create()
{
	set_name(HIY "¹��" NOR, ({ "lurong", "herb_lurong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 10000);
        	set("weight", 70);
set("base_unit","��");
	}
	setup();
}
