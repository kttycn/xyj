// shespear.c
// stone created 20020308


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(WHT "�ɰ���ì" NOR, ({ "snake spear","qiang","spear" }));
  set_weight(20000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "֧");
    set("value", 10000);
    set("material", "steel");
    set("long", "��ǹ�����ŷ�ʹ����������ڵ�ǹ������������ìͷ���������ţ�ʮ�ֹ��졣\n");
    set("wield_msg", "$Nһ��ŭ�𣬷��ֳ���һ֧$n��ֻ�������������������ˡ�\n");
  }
  init_spear(120);
  setup();
}

