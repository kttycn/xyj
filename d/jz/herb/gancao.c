// gancao.c

#include "herb.h"

void create()
{
        set_name( RED"�ʲ�" NOR, ({ "gan cao", "herb_gancao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 500);
                set("weight", 60);
set("base_unit","��");
        }
        setup();
}
