// by smile 12/13/1998

#include <ansi.h>
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name(HIY "��������" NOR, ({"jinyi pifeng", "pifeng"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "һ���������Ƶ����硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 12500);
    set("armor_prop/armor", 60);
  }
  setup();
}


