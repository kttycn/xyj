#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int extra,lvl,lv;
 int i;
 object weapon;
 
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
 	return notify_fail("�ޱߵ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�"
	&& !me->query("guild") )
 	return notify_fail("���ޱߵ�����ֻ���޵׶����˲ſ����ã�\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "blade" )
 	return notify_fail("�������޵�������ʹ���ޱߵ�����\n");
 if( (int)me->query("force") <= 1000 )
 	return notify_fail("����������������ʹ���ޱߵ�����\n");

 extra = me->query_skill("kugu-blade",1) / 5;
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg = HIR  "$Nʹ���ۿݹǵ����ݵ��ޱߵ��������е�"+ weapon->name() +"бб������$n�پ�����һ�ϣ�" NOR;
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
 msg =  HIW "$N����������$n��Χ������ţ�ǡ���ޱߵ�����\n" NOR;
        message_vision(msg, me, target);
lvl=extra/10;
if(lvl>3) lvl =3;
for(i=0;i<=lvl;i++)
 {
 msg = HIY "$N����һ����\n" NOR;
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
 message_vision(msg,me,target);
}
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->add("force", -300);
 me->start_busy(1+lvl);
 return 1;
}