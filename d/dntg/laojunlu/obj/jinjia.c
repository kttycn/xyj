// jinjia.c ���
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name( HIY "�����Ӽ�" NOR, ({"golden armor","jinjia", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
     set("long", HIC"һ������֯�͵ı��ף�\n"NOR);
                set("material", "steel");
                set("value", 0);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("no_sell", 1);
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", -5);
        }
        setup();
}


