// chuanwu.c

#include "herb.h"

void create()
{
	set_name(WHT "����" NOR, ({ "chuanwu", "herb_chuanwu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 200);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
