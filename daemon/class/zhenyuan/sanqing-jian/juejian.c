#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������������\n");

     if(me->query("family/family_name") != "��ׯ��"
	&& !me->query("guild") )
                return notify_fail("[�������]����ׯ�۲���֮�ܣ�\n");
        if(!me->is_fighting())
                return notify_fail("�����������ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

            if((int)me->query("force") < 500 )
                        return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("sanqing-jian", 1) < 120)
                return notify_fail("������彣�����𻹲�����ʹ����һ�л������ѣ�\n");
               
               if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("����������������Ԫ�񹦲���ʹ�á�\n");
          
              me->delete("env/brief_message");
            target->delete("env/brief_message");

message_vision(HIC"\n$N��������һ����������������أ������ڿն��������$nʹ���ˣ���������ݣ�\n"NOR,me,target);

        me->set_temp("SQJ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("SQJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete_temp("SQJ_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}

