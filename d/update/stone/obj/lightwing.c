// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;
inherit F_UNIQUE;

void create()
{
  set_name(HIW"光之翼" NOR, ({"light wing", "guang zhiyi","surcoat","wing"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", HIW"一对用满天星光所制羽翼，星光闪闪。\n"NOR);
    set("material", "leather");
    set("unit", "对");
    set("value", 0);
    set("wear_msg", "霞光万丈，$N的背后现出一对镶嵌了所有星辰光芒的光之羽翼，$N浮身半空，轻盈得仿如无物。\n");
    set("unequip_msg", "$N微微一笑，背上的$n光芒暗淡下来，$n消失了。\n");
//    一对彷佛镶嵌了所有星辰光芒的光之羽翼
    set("no_sell", "凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
    set("no_put", "这光之翼装不进容器里去。\n");
    set("no_drop", "这么稀世难求的宝甲圣衣，扔了多可惜呀！\n");
//    set("no_give", "这可是宝甲圣衣啊，哪能随便给人？\n");
    set("no_get", HIR"你刚摸到光之翼，$n发出耀眼夺目的钻石星辰光芒。\n"NOR);
    set("armor_prop/armor", 100);//参考锦衣披风60
    set("armor_prop/dodge", 200);
  }
  set("is_monitored",1);
  setup();
}


