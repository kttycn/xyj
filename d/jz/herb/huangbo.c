// huangbo.c

#include "herb.h"

void create()
{
        set_name(YEL "�ư�" NOR, ({ "huang bo", "herb_huangbo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 1000);
                set("weight", 50);
set("base_unit","��");
        }
        setup();
}
