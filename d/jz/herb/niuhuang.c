// niuhuang.c

#include "herb.h"

void create()
{
	set_name(HIY "ţ��" NOR, ({ "niu huang", "herb_niuhuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 1000);
        	set("weight", 60);
set("base_unit","��");
	}
	setup();
}
