// jie 2001-2-3
// chixin-jian ���հ׷�
// modi by xintai 2/29/2001

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,lvl;
        int i;
        object weapon,ob;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���հ׷�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
        if(me->query("family/family_name")!="��˿��"
	&& !me->query("guild") )
		return notify_fail("�����հ׷���ֻ����˿�����˲ſ����ã�\n");
        if( (string)weapon->query("skill_type") != "sword" )
        	return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
        if ( (string) me->query_skill_mapped("sword") != "chixin-jian")
        	return notify_fail("���հ׷�ֻ�ܺͳ����鳤������ͣ�\n");
        if (me->query_skill_mapped("force")!="jiuyin-xinjing")
                return notify_fail("ֻ���þ����ľ��������ú��հ׷���\n");
        if (me->query_skill("chixin-jian",1) < 80
         || me->query_skill("yueying-wubu",1) < 80)
        	return notify_fail("��ļ��ܲ������޷�ʹ�����հ׷���\n");
                
        if((int)me->query("force") < 100 )
                return notify_fail("�������������\n");
        if((int)me->query("kee") < 100 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");
        extra = me->query_skill("chixin-jian",1) / 15;
        extra += me->query_skill("yueying-wubu",1) / 15;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        me->receive_damage("kee", 100);
        msg = HIM  "$N��̤����Ӱ�貽�ݣ��������裬ʹ���۳����鳤�����ݵľ��裭��
        \n"HIR"             ������"HIW"�׷���
        \n"MAG"����ֻ��$N����ƮƮ��ȹ�����ǣ�������Թ���ɷ��\n\nʹ�����龡�⴦�������������е�"+ weapon->name() +MAG"��˫ָ�ֵ����ޱ������뵰����$n��\n\n" NOR;
        message_vision(msg, me, target);
        msg =  HIW ""+ weapon->name() +HIW"���糤����գ��·���ʧ��������\n\n" NOR;
        message_vision(msg, me, target);
        me->clean_up_enemy();
        ob = me->select_opponent();
        lvl=extra;
    	if(lvl>3) lvl =3;
        for(i=0;i<lvl;i++)
        {
        msg = HIY "$N��Ŷ�����������䣭��������Ϊ�������Ƶ˼�ź��籡������\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 2);
        }
        me->add("force",-200);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
   	me->start_busy(2+random(lvl));
        return 1;
}
