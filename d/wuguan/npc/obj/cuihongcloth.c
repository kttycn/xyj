//Cracked by Roath
// cuihongcloth.c  �����
//
// by yfengf

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG"��"NOR+HIR"����"NOR, ({ "cloth" }) );
        set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

