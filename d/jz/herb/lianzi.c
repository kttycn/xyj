// lianzi.c

#include "herb.h"

void create()
{
        set_name(HIG "����" NOR, ({ "lianzi", "herb_lianzi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 600);
                set("weight", 20);
set("base_unit","��");
        }
        setup();
}
