// xingren.c

#include "herb.h"

void create()
{
        set_name(HIY "����" NOR, ({ "xingren", "herb_xingren" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 60);
                set("weight", 20);
set("base_unit","��");
        }
        setup();
}
