// ercha.c

#include "herb.h"

void create()
{
        set_name(GRN "����" NOR, ({"erhua", "herb_erhua"}));
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
