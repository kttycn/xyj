// huajiao.c

#include "herb.h"

void create()
{
        set_name(YEL "������" NOR, ({ "chuan huajiao", "huajiao", "herb_huajiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 400);
                set("weight", 100);
set("base_unit","��");
        }
        setup();
}
