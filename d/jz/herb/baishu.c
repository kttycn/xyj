// baishu.c

#include "herb.h"

void create()
{
        set_name(HIW "����" NOR, ({ "baishu", "herb_baishu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit","��");
                set("base_unit", "��");
                set("value", 4000);
                set("base_weight", 100);
        }
        setup();
}
