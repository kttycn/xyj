#include <weapon.h>

inherit MACE;

void create()
{
  set_name("��ڱ�", ({"bamboo mace", "mace" }) );
  init_mace(15);
  set("unit", "��");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 500);
    set("material", "wood");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

