// xiongdan.c

#include "herb.h"

void create()
{
	set_name(HIR "�ܵ�" NOR, ({ "xiongdan", "herb_xiongdan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 5000);
        	set("weight", 70);
set("base_unit","��");
	}
	setup();
}
