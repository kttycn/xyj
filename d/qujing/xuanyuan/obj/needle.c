// gangjian.c
#include <ansi.h>
#include <weapon.h>
inherit NEEDLE;

void create()
{
        set_name("�廨��", ({ "zhen", "needle" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����Ե���������.\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N����һ��,���������һ��$n��\n");
                set("unwield_msg", "����һ��,���е�$n������.\n");
        }
        init_needle(15);
        setup();
}
