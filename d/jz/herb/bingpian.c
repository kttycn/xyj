// bingpian.c

#include "herb.h"

void create()
{
        set_name(HIW "��Ƭ" NOR, ({ "bingpian", "herb_bingpian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit","��");
                set("base_unit", "��");
                set("value", 7000);
                set("weight", 100);
        }
        setup();
}
