// zhentian-arrow.c 震天箭

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("震天箭", ({ "zhentian jian", "arrow", "jian", "zhentian", "zhentian jian", }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","震天箭乃是后羿当年射日所用之箭。。\n");
    set("unit", "壶");
	set("rigidity", 9);
    set("base_unit", "枝");
    set("base_weight", 400);
    set("base_value", 500);
  }
  set_amount(50);
  init_archery(80);
  setup();
}

