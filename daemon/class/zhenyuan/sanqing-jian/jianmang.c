
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int ap, myexp, yourexp, extra;
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("��ý�âֻ����ս����ʹ��.\n");
	if(me->query("family/family_name") != "��ׯ��"
	&& !me->query("guild") )
		return notify_fail("[��ý�â]����ׯ�۲���֮�ܣ�\n");
	if((int)me->query_skill("sanqing-jian",1) < 80)
		return notify_fail("������彣���ȼ�������!!\n");
	if( (int)me->query("max_force") < 800)
		return notify_fail("�������̫��,�����³���â!!\n");
	if( (int)me->query("force") < 400)
		return notify_fail("�������������!!\n");
	if(! me->query_temp("weapon"))
		return notify_fail("������ý�����ʹ�á�"+HIR"��ý�â"NOR+"����\n");
	ap = (int) me->query("spi");
	myexp = (int)me->query("combat_exp");
	yourexp = (int)target->query("combat_exp");
	msg = HIC"\n$Nһ����Ц,���г���бָ����,�����³�һ�ų������â,�������԰���������!\n"
"$n�������,���Ž�âȴ�͵ñ���,����$n������ֱ�����!!\n\n" NOR;
	message_vision(msg, me ,target);
	if( random(myexp*5) > yourexp)
	{
		msg = HIR"\nֻ��$nһ���Һ�,��â��$n�Ķ�ͷ�ӹ�,����һ��Ѫ��!!\n" NOR;
		message_vision(msg, me ,target);
		msg = HIW"\n��â���羭�������ʴ�ת��һת,�ַɻ�$N�����.\n" NOR;
		message_vision(msg, me ,target);
		target->start_busy(2+random(3));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		me->start_busy(1);
	}
	else {
		msg = HIY"\n$nȴʶ�����Ž�â������,����ԶԶ����һ��.\n" NOR;
		message_vision(msg, me ,target);
		me->start_busy(2);
	}
	me->add("force",-120);
	return 1;
}
