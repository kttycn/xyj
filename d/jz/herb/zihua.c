// zihua.c

#include "herb.h"

void create()
{
	set_name(MAG "�ϻ�" NOR, ({ "zihua", "herb_zihua" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 50);
        	set("weight", 20);
set("base_unit","��");
	}
	setup();
}
