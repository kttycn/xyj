//Cracked by Roath
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("铁锤", ({"iron hammer", "chui", "hammer"}));
        set_weight(39000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄铁锤，锤身略显青色．\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg","$N拿出一柄$n，掂了掂份量，握在手中．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_spear(40);
        setup();
}

