// ruxiang.c

#include "herb.h"

void create()
{
	set_name(CYN "���" NOR, ({ "chai hu", "herb_chaihu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 4000);
        	set("weight", 60);
		set("base_unit","��");
	}
	setup();
}
