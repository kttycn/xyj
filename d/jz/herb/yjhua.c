// yjhua.c

#include "herb.h"

void create()
{
	set_name(YEL "���" NOR, ({ "yang jinhua", "herb_yjhua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 400);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
