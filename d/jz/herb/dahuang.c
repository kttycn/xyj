// dahuang.c

#include "herb.h"

void create()
{
	set_name(HIY "���" NOR, ({ "da huang", "herb_dahuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 7000);
        	set("weight", 100);
set("base_unit","��");
	}
	setup();
}
