// zzfen.c

#include "herb.h"

void create()
{
	set_name(HIW "�����" NOR, ({ "zhenzhu fen", "herb_zzfen" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "������ҩҩ�ġ�\n");
		set("unit", "��");
		set("value", 9000);
        	set("weight", 30);
set("base_unit","��");
	}
	setup();
}
