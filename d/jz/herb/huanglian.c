// huanglian.c

#include "herb.h"

void create()
{
        set_name(YEL "����" NOR, ({ "huanglian", "herb_hl" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 300);
                set("weight", 50);
set("base_unit","��");
        }
        setup();
}
