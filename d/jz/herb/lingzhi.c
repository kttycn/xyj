// lingzhi.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG "��֥" NOR, ({ "lingzhi", "herb_lingzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "������ҩҩ�ġ�\n");
                set("unit", "��");
                set("value", 20000);
                set("weight", 70);
        }
        setup();
}
