// beimu.c

#include "herb.h"

void create()
{
        set_name(HIC "��ĸ" NOR, ({ "bei mu", "herb_beimu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 7000);
		set("base_unit","��");
                set("weight", 100);
        }
        setup();
}
