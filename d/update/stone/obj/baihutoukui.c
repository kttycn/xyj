//created by smile 12/13/1998
#include <ansi.h>
#include <armor.h>

inherit HEAD;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"白虎战盔"NOR, ({ "baihu zhankui", "zhankui","bonnet" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIW"一件用西方圣兽白虎之风牙所制的战盔，银光闪闪。\n"NOR);
    		set("material", "gold");
    		set("unit", "件");
    		set("value", 0);
    		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
    		set("no_put", "这白虎战盔装不进容器里去。\n");
    		set("no_drop", "这么稀世难求的宝盔圣帽，扔了多可惜呀！\n");
    		set("no_give", "这可是宝盔神胄啊，哪能随便给人？\n");
    		set("no_get", HIW"你刚摸到白虎战盔，突然白虎战盔中现银色的西方圣兽白虎，张牙舞爪，你不由胆战心惊。\n"NOR);
    		set("armor_prop/armor", 100);
        }
        set("is_monitored",1);
        setup();
}

