// dangui.c

#include "herb.h"

void create()
{
        set_name(HIG "����" NOR, ({ "danggui", "herb_danggui" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 500);
                set("weight", 70);
set("base_unit","��");
        }
        setup();
}
