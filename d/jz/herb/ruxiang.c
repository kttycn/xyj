// ruxiang.c

#include "herb.h"

void create()
{
	set_name(HIW "����" NOR, ({ "ru xiang", "herb_ruxiang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 500);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
