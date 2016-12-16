//created by smile 12/13/1998
#include <ansi.h>
#include <armor.h>

inherit WRISTS;
inherit F_UNIQUE;

void create()
{
        set_name(HIR"朱雀护腕"NOR, ({ "zhuque huwan", "huwan","wrists" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIR"一件用南方圣兽朱雀之骨所制的护腕，火光隐隐。\n"NOR);
    		set("material", "gold");
    		set("unit", "件");
    		set("value", 0);
    		set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
    		set("no_put", "这朱雀护腕装不进容器里去。\n");
    		set("no_drop", "这么稀世难求的护手宝物，扔了多可惜呀！\n");
    		set("no_give", "这可是护手宝物啊，哪能随便给人？\n");
    		set("no_get", HIR"你刚摸到朱雀护腕，突然朱雀护腕中现朱色的南方圣兽朱雀，张牙舞爪，你不由胆战心惊。\n"NOR);
    		set("armor_prop/armor", 100);
        }
        set("is_monitored",1);
        setup();
}

