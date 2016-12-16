// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
  set_name(YEL "玄武披风" NOR, ({"xuanwu pifeng", "pifeng","surcoat"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", YEL"一件用北方圣兽玄武之皮毛所制的披风，金光闪闪。\n"NOR);
    set("material", "leather");
    set("unit", "件");
    set("value", 0);
    set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
    set("no_put", "这玄武披风装不进容器里去。\n");
    set("no_drop", "这么稀世难求的宝甲圣衣，扔了多可惜呀！\n");
    set("no_give", "这可是宝甲圣衣啊，哪能随便给人？\n");
    set("no_get", YEL"你刚摸到玄武披风，突然玄武披风中现出玄色的北方圣兽玄武，张牙舞爪，你不由胆战心惊。\n"NOR);
    set("armor_prop/armor", 100);//参考锦衣披风60
  }
  set("is_monitored",1);
  setup();
}


