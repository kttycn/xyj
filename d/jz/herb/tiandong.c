// tiandong.c

#include "herb.h"

void create()
{
        set_name(HIC "�춬" NOR, ({ "tiandong", "herb_tiandong" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 200);
                set("weight", 90);
set("base_unit","��");
        }
        setup();
}
