//fengdao.c  ���絶��
#include <ansi.h>
#include "/daemon/skill/eff_msg.h";

inherit SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("���絶��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if ((string)me->query("family/family_name")!="�����"
	&& !me->query("guild") )
		return notify_fail("[�絶]ֻ�з�������˲���ʹ�á�\n");
	if( (int)me->query_skill("wuzu-xinfa", 1) < 100 )
		return notify_fail("��������ķ���򲻹���ʹ�������絶����\n");

	if( (int)me->query_skill("tenglong-finger", 1) < 100 )
		return notify_fail("�������ָ��������������ʹ�á��絶����\n");

	if( (int)me->query("force") < 1000 )
		return notify_fail("���������Ϊ�������ߡ�\n");

	msg = HIM "$N��Ȼ�����Ϣ����һɢ����ʼ�ۼ�������˷���������\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(3);
	call_out("num1",3,me,target);
	return 1;
}

void num1(object me,object target)
{
	string msg;
msg = HIY "ֻ��$Nȫ��⻪���𣬺�Ȼ������˷����ϳ���Ʈ�ŵĹ����$N���У�$NѸ�ٵı�����������
�Ƶķ�����֮�У�$nҲ����Щ��Χ֮�ڡ���\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(3);
	call_out("num2",3,me,target);
	return;
}

void num2(object me,object target)
{
	string msg;
	int damage;
	msg = HIG"$Næ����Ϣ�������ۣ����ϳɷ�������������������Χס$n��\n"NOR;
	msg += HIG"$N��ʱ�����Ĵȣ�����һ�������ٹ�������������ƬͬʱѸ�ٵ���$n��ȥ������ǳ��Ŷ�����\n����֮һ�����絶��\n"NOR;
	message_vision(msg, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5) {
		damage = (int)me->query_skill("tenglong-finger", 1)*2+(int)me->query_skill("wuzu-xinfa",1);
		damage = damage/2 + random(damage);
		me->add("force", -500);
		msg= HIR"���ٹ�Ƭ��$n����������ʮ�������ۣ�$n�Ļ�����������ɢ��������䣬֧�����Լ����˵�
������������������Ϣ����ʱ��ʮ�����ֲ����ϡ��ֱۡ��ر����˺۲����ļ�����������Ѫ����\n"NOR;
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/(random(3)+1));
		message_vision(msg, me, target);
	} else {
		msg = HIC"����$p������$P����ͼ��������һ�ߡ�\n"NOR;
		message_vision(msg, me, target);
	}

	if(!target->is_fighting(me)) target->fight_ob(me);
	return;
}
