
#include "herb.h"

void create()
{
        set_name(HIY "����" NOR, ({ "jiu zi", "jiuzi_hupo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 900);
                set("weight", 20);
set("base_unit","��");
        }
        setup();
}
