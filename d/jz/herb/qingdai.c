// qingdai.c

#include "herb.h"

void create()
{
        set_name(HIC "����" NOR, ({ "qing dai", "herb_qingdai" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit","��");
                set("base_value", 1000);
                set("value",1000);
                set("base_weight", 100);
        }
        setup();
}
