// hafen

#include "herb.h"

void create()
{
	set_name(RED "���" NOR, ({ "ha fen", "herb_hafen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 5000);
        	set("weight", 50);
set("base_unit","��");
	}
	setup();
}
