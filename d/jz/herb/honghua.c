// honghua.c

#include "herb.h"

void create()
{
	set_name(HIR "�컨" NOR, ({ "honghua", "herb_honghua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 800);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
