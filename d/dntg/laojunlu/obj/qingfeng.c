
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
   set_name( MAG "���ϸ�꽣" NOR, ({ "qingfeng sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_put", 1);
                set("value", 0);

     set("material", "steel");
     set("long", "����һ����ϸ�ֳ��Ľ�������������\n");
     set("wield_msg", "һ�����������$N�����Ѷ��˰�$n��\n");
     set("unequip_msg", "$N�������е�$n��\n");
   }
   init_sword(50);
   setup();
}
