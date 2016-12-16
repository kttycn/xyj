#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int ap,dp,damage,chance;
        string msg;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��������Ӱ����\n");
        if(!me->is_fighting())
                return notify_fail("��������Ӱ��ֻ����ս����ʹ�ã�\n");
        if(me->query("family/family_name")!="��ʥ��"
	&& !me->query("guild") )
                return notify_fail("������ʥ�ŵĲ����á�������Ӱ����\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 500 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("wuying-sword", 1) < 100)
                return notify_fail("�����Ӱ����Ϊ��������ʹ����һ�л������ѣ�\n");

        msg = HIR"\n$N����ζ��缲�磬�Լ�����ٶ�˲��ӳ���ǧ�Űپ�ʮ�Ž���������Ӱֱ��$n��\n"NOR;
        ap = me->query_skill("sword");
        ap = ap*ap*ap / 20;
        dp = target->query("combat_exp"); 
        chance = (int)(random( ap + dp ) / dp * 100);
        if (target->is_busy()) chance *= 3;
        if( chance > 40 ) {
                damage = me->query_skill("sword") * 2 + me->query("force_factor");
                if (damage > 800) damage = 750+random(75);
                target->receive_damage("kee",damage);
                target->receive_wound("kee",damage/3);
target->start_busy(random(1)+1);
                msg += CYN"���$n��$N�ġ�������Ӱ������������\n"NOR;
        }
        
        else 
                msg += "���Ǳ�$n�㿪�ˡ�\n"NOR;
        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
   
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->add("force",-200-me->query("force_factor"));
        me->start_busy(3);
        return 1;
}
