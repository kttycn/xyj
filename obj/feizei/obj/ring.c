#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
        set_name(HIW"白玉戒指"NOR, ({"baiyu jiezhi", "ring"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "上古十二神物之：白玉戒指。\n");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",0);
                set("no_get",0);
                set("material", "gold");
                set("armor_prop/armor", 50);
             }
        setup();
}
