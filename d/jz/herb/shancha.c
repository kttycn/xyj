// shancha.c

#include "herb.h"

void create()
{
	set_name(WHT "ɽ�軨" NOR, ({ "shancha", "herb_shancha" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 200);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
