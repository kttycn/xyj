// zihua.c

#include "herb.h"

void create()
{
        set_name(HIC "����" NOR, ({ "duanxu", "herb_duanxu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 500);
                set("weight", 20);
set("base_unit","��");
        }
        setup();
}
