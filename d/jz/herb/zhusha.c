// zhusha.c

#include "herb.h"

void create()
{
        set_name(RED "��ɰ" NOR, ({ "zhu sha", "herb_zhusha" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 400);
                set("weight", 30);
set("base_unit","��");
        }
        setup();
}
