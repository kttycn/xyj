// shexiang.c

#include "herb.h"

void create()
{
        set_name(YEL "����" NOR, ({ "she xiang", "herb_shexiang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "Ƭ");
                set("value", 2000);
                set("weight", 60);
set("base_unit","Ƭ");
        }
        setup();
}
