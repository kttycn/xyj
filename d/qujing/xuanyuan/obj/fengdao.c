// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// blade.c

#include <weapon.h>
#include <ansi.h>
inherit BLADE;

void create()
{
   set_name(HIC"���µ�"NOR, ({"fengyue dao", "dao", "blade"}) );
   set_weight(6000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 500);
     set("material", "iron");
     set("long", "����һ��Ư����˫��Ϸ�µ���\n");
     set("wield_msg", "$N���һ��$n��৵��������С�\n");
     set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�\n");
   }
   init_blade(75);
   setup();
}
