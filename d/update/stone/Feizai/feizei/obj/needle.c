#include <weapon.h>
#include <ansi.h>

inherit NEEDLE;

void create()
{
        set_name(HIC"�ɺ�����"NOR, ({ "xianhe needle","zhen","needle" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "iron");
                set("no_get",1);
                set("long", WHT"�Ϲ�ʮ�����֮һ���ɺ����롣\n"NOR);
                set("wield_msg", "$N��������һ��$n�����Ͻ������ޡ�\n");
        }
        init_needle(50+random(50));
        setup();
}
