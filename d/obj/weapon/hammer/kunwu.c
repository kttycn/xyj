// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
   set_name( "��ٽ�", ({ "kunwu jian", "kunwu", "jian" }) );
   set_weight(50000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 5000);
     set("material", "gold");
     set("long", "����һ���޽�����Ȼ�����д��˸��������֣����޷����У������ޱȣ�ͨ������������ʹ�á�\n");
     set("wield_msg", "$N����ȫ����������˫�����һ��$n��\n");
     set("unwield_msg", "$N��$n��������Ĩ��Ĩ���ϵĺ���\n");
   }
   init_hammer(60);
   setup();
}

