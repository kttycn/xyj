// bohe

#include "herb.h"

void create()
{
        set_name( HIC"����" NOR, ({ "bo he", "herb_bohe" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("base_unit", "ƿ");
                set("unit","ƿ");
                set("value", 5000);
                set("weight", 50);
        }
        setup();
}
