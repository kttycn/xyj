#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(YEL"С���"NOR, ({"xiao magua", "cloth", "magua"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�Ϲ�ʮ�����֮��С��ӡ�\n");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("no_get",1);
                set("armor_prop/armor", 50);
             }
        setup();
}
