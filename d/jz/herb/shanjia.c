//��ɽ��

#include "herb.h"

void create()
{
        set_name(RED "��ɽ��" NOR, ({ "chuanshan jia", "herb_shanjia" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("value",5000);
                set("unit","��");
                set("base_unit", "��");
                set("base_value", 5000);
                set("base_weight", 50);
        }
        setup();
}
