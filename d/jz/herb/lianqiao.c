// lianqiao

#include "herb.h"

void create()
{
        set_name( HIY"����" NOR, ({ "lian qiao", "herb_lianqiao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 500);
                set("weight", 50);
set("base_unit","��");
        }
        setup();
}
