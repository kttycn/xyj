// hugu.c

#include "herb.h"

void create()
{
        set_name(HIW "����" NOR, ({ "hu gu", "hugu", "herb_hugu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 900);
                set("weight", 100);
set("base_unit","��");
        }
        setup();
}
