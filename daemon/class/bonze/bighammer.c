// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// bighammer.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ�ô�����ħ�ƴ�˭��\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("��ķ���������\n");

        if((int)me->query("sen") < 10 )
                return notify_fail("���޷����о������������Լ��ˣ�\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("��ʧ���ˣ�\n");
                return 1;
        }

   msg = HIC
"$N�������˼������ģ�������ֳ����У���Ҷ�����ߣ�������ִ\nһ���޴��ޱȵĽ�ħ�ƣ�������һ����$n��ͷ���£�\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {
                damage = (int)me->query("max_mana") / 10 +
random((int)me->query("eff_sen") / 5);
                damage -= (int)target->query("max_mana") / 10 +
random((int)target->query("eff_sen") / 5);      
     damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
                if( damage > 0 ) {
     msg += HIC "����Ҹ����ţ����û��$n�ұ⣡\n" NOR;
//finally damage also depends on enabled spells level.
     damage +=random((damage*(int)me->query_skill("spells"))/80);
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("buddhism", 1, 1);
                }
       else {
//here, cast failed and the target's mana_factor will be added to the previous 
//damage to hurt yourself:(...note damage<0.
     msg += HIC "�����ħ�Ʊ�$n�Է�������������������$N��\n" NOR;
     damage -= (int)target->query("mana_factor");
     damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
                        me->improve_skill("buddhism", 1, 1);
       }
             } 
   else
                msg += "���Ǳ�$n�㿪�ˡ�\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);
//damage=0 corresponding to "���Ǳ�$n�㿪�ˡ�\n"--no report.   

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
target->kill_ob(me);
                }
                me->fight_ob(target);
if(target->query("eff_kee")<0)
{
CHANNEL_D->do_channel(target,"rumor",target->query("name")+"��"+me->query("name")+"���������Ϸ𷨡�������ħ�ơ������ˡ�\n");
      target->die();
     }

        }

        me->start_busy(1+random(2));
        return 3+random(5);
}

