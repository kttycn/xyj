//Cracked by Roath
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({"iron hammer", "chui", "hammer"}));
        set_weight(39000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������������������ɫ��\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N�ó�һ��$n�����˵�������������У�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_spear(40);
        setup();
}

