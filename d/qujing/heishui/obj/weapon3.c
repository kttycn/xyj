#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("��ʯ��", ({ "fengshi pa", "fengshi", "pa" }) );
  init_rake(40);
  set("unit", "��");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "iron");
  }
  set("wield_msg","$N����$n�������\n");
  setup();
}

