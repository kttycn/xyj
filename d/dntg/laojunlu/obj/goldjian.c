
#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIY "�����װ�" NOR, ({"gold mace", "mace", "goldmace", "jinjian"}));
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 0);
    set("no_give", 1);
    set("no_sell", 1);
    set("no_get", 1);
    set("no_put", 1);
    set("material", "gold");
    set("long", "�ؼ��洫�Ľ�װﵣ���ɳ����Ϊ���������˺����͡�\n");
    set("wield_msg", "$N�����$n���૵���ﵶ���ﵶ���������һ�أ�\n");
    set("unwield_msg", "$N������$n��������һ����������ﵹ�Ȼ�����۷磡\n");
  }
  
  init_mace(50);
  setup();
}

