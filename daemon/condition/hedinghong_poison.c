//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
   if( duration < 1 ) return 0;
   if( !living(me) ) {
      message("vision", HIR""+me->name() + "���к׶���綾����������Ҫ�����ˡ�\n"NOR, environment(me), me);
   }
   else {
      tell_object(me, HIR "�����ϵľ綾�����ˡ�\n" NOR );
      message("vision", HIR""+me->name() + "���к׶���綾����������Ҫ�����ˡ�\n"NOR,
            environment(me), me);
   }
   me->receive_wound("kee", 100);
   me->receive_damage("kee", 100);
   me->apply_condition("hedinghong_poison", duration - 1);

   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
