// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIC"凤月刀"NOR, ({"fengyue dao", "dao", "blade"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "柄");
     set("value", 500);
     set("material", "iron");
     set("long", "这是一柄漂亮的双凤戏月刀。\n");
     set("wield_msg", "$N抽出一柄$n，唰地握在手中。\n");
     set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
   }
   init_blade(75);
   setup();
}
