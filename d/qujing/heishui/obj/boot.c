#include <armor.h>

inherit BOOTS;

string *names = ({
  "з��ѥ",
  "Ϻ��ѥ",
});

string *ids = ({
  "xiejia xue",
  "xiake xue",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i], "xue", "shoes"}));
  set_weight(2000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "˫");
   set("value", 200);
   set("armor_prop/armor", 10);
   set("armor_prop/dodge", -1);
  }
  set("no_sell",1);
  setup();
}

