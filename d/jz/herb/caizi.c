// caizi.c

#include "herb.h"

void create()
{
        set_name(HIW "�׻�����" NOR, ({ "baihua caizi", "caizi", "herb_caizi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 500);
                set("weight", 100);
                set("base_unit","��");
        }
        setup();
}
