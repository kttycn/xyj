// gsliu.c

#include "herb.h"

void create()
{
	set_name(CYN "��ʯ��" NOR, ({ "gan shiliu", "herb_gsliu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "Ƭ");
		set("value", 200);
        	set("weight", 75);
set("base_unit","Ƭ");
	}
	setup();
}
