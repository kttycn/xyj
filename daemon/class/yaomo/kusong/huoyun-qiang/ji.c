//ji.c by yushu 2000.9
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i,j,damage;
        weapon = me->query_temp("weapon");
        
              if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ǹ����\n");

     if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("����ǹ��ֻ�л��ƶ����˲ſ����ã�\n");
        if(!me->is_fighting())
                return notify_fail("����ǹ��ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");
               
        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
              
        if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("��ǹ������ϻ�ħ�ķ�����ʹ�á�\n");
          


   i=(int)me->query_skill("huoyun-qiang",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("��Ļ���ǹ���𻹲�����ʹ����һ�л������ѣ�\n");

   message_vision(HIR"\nֻ��$N��"+weapon->query("name")+HIR"�����˿���Ѫ,���һ��:��ǹ��\n"NOR,me);

   me->delete("env/brief_message");
   target->delete("env/brief_message");

   me->set_temp("HYQ_perform", 8);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

   me->delete_temp("HYQ_perform");

   me->receive_damage("sen", 100+random(100));
   me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

