#include <ansi.h>

#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIY"����������"NOR, ({ "dragon stick","gun", "bang" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("material", "steel");
                set("long", "һ���������������ĳ�����\n");
                set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
                set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
        init_stick(50);
        setup();
}

