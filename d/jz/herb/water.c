// water.c

#include "herb.h"

void create()
{
        set_name(WHT "��ˮ" NOR, ({ "chun shui", "herb_chunshui" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����������ҩ�Ĵ�ˮ��\n");
                set("unit", "ƿ");
                set("value", 10);
                set("weight", 50);
                set("no_drop",1);
set("base_unit","ƿ");
        }
        setup();
}
