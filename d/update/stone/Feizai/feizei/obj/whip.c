#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIM"��˿"NOR, ({"qing si","whip"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"�Ϲ�ʮ�����֮һ����˿\n"NOR);
                set("unit", "��");
                set("no_put",1);
                set("value", 0);
                set("no_zm",1);
                set("no_give",1);
   		set("no_get",1);
        }
        init_whip(50+random(50));
        setup();
}

