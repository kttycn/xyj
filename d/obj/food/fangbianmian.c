// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("方便面", ({"fangbian mian", "mian"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一包方便面。\n");
    set("unit", "包");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 70);
  }
}
