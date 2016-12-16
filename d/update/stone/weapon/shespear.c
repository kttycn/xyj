// shespear.c
// stone created 20020308


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(WHT "丈八蛇矛" NOR, ({ "snake spear","qiang","spear" }));
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "支");
    set("value", 10000);
    set("material", "steel");
    set("long", "此枪乃是张飞使过兵器，黝黑的枪身，弯弯曲曲的矛头，如蛇吐信，十分怪异。\n");
    set("wield_msg", "$N一声怒吼，反手抄起一支$n，只见寒光闪闪，冷气逼人。\n");
  }
  init_spear(120);
  setup();
}

