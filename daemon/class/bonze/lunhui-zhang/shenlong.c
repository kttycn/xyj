// xian.c  ��������
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("[1;33m���������֡�ֻ�ܶ�ս���еĶ���ʹ�á�[1;0m\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->query("family/family_name")!="�Ϻ�����ɽ"
	&& !me->query("guild") )
		return notify_fail("���Ƿ��ŵ��Ӳ����á��������֡���\n");

	if( (int)me->query_skill("lunhui-zhang", 1) < 120 )
		return notify_fail("����ֻ��ȷ�������죬����ʹ�á��������֡���\n");

	if( (int)me->query_skill("lotusforce", 1) < 120 )
		return notify_fail("��������ķ������ߣ��������������˵С�\n");

	if( (int)me->query("force", 1) < 1500 )
		return notify_fail("����������̫��������ʹ�á��������֡���\n");

	msg = MAG "ֻ��$N΢΢һЦ������һ����,��ʹ������Ԧ�Ⱦ�������$n��\n"NOR;

	if( !target->is_killing(me) ) target->kill_ob(me);

	if (random(me->query_skill("force")*2.2)> target->query_skill("force"))
	{
		target->start_busy(random(1));

		damage = (int)me->query_skill("lotusforce", 1)/2;
		damage = damage +  (int)me->query_skill("lotusmove", 1)/2;
		damage = damage +  (int)me->query_skill("lunhui-zhang", 1)/2;

		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage*2/3);
		msg += HIY"$N�������Ȼ���һ������,�ڿն���,ٿ������$n,\n$nֻ��һ�ɴ�������ǵذ�ѹ��,��ʱ��ǰһ������������,�۵����һ����Ѫ����\n"NOR;
		me->start_busy(2);
	} else {
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	me->add("force",-200);
	return 1;
}
