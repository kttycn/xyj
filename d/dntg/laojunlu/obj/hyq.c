//hyq.c @waiwai  2000/07/10

#include <ansi.h>

#include <weapon.h>

inherit SPEAR;

void create()
{
   set_name(HIB"����"+HIR"��ӣǹ"NOR, ({ "hyq","qiang","spear" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("value", 0);
     set("no_give", 1);
     set("no_sell", 1);
     set("no_get", 1);
     set("no_put", 1);

     set("material", "wood");
     set("long", "һ�˳�ǹ��\n");
     set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
     set("unwield_msg", "$N����һ������$n����˳�ڱ���\n");
   }
   init_spear(50);
   setup();
}
