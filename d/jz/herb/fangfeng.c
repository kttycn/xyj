// fangfeng.c

#include "herb.h"

void create()
{
	set_name(HIB "����" NOR, ({ "fang feng", "herb_fangfeng" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "Ƭ");
		set("value", 500);
        	set("weight", 40);
set("base_unit","Ƭ");
	}
	setup();
}
