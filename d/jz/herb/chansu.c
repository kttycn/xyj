// chansu.c

#include "herb.h"

void create()
{
        set_name(HIW "���" NOR, ({ "chansu", "herb_chansu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 1000);
                set("weight", 20);
		set("base_unit","��");
        }
        setup();
}
