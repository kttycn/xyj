// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
          if(me->query("family/family_name") != "��ԯ��Ĺ"
	&& !me->query("guild") )
        return notify_fail("�㲻�Ǻ��꣡\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
               return notify_fail("��Ҫ��˭ʩչ�����ٻ�������\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

      if( me->query_skill("xuanhu-shentong", 1) < 30 )
                return notify_fail("���������ͨ�ȼ�������\n");
 
        if((int)me->query("sen") < 10 )
              return notify_fail("���޷����о��������ɻ���\n");

        me->add("mana", -2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 60);

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

        msg = HIC
"$N�����дʣ�ͻȻ������ʮ�ֹ��أ�������ʱֻ����һ���������\n"
 "��������һֻ���ſ��ſ�Ѫ������$n���˹�����\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {

     damage = me->query("max_mana")/15+2*random((int)me->query("mana_factor"));
       
        if( damage > 0 ) {
                msg += HIR "���$n������������$Nҧ��ѪͷѪ����\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("xuanhu-shentong", 1, 1);
                }
       else {
                        msg += HIC "���һ�����������˹�ȥ��\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);

                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
       }
             }
   else
                msg += "���Ǳ�$n�㿪�ˡ�\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
                target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}
