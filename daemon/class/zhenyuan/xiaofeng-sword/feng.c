#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����縧�桹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
     if(me->query("family/family_name") != "��ׯ��"
	&& !me->query("guild") )
		return notify_fail("[��縧��]����ׯ�۲���֮�ܣ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("xiaofeng-sword", 1) < 50 )
		return notify_fail("���������½�����������죬����ʹ�á���縧�桹��\n");
	if( (int)me->query("force") < 300 )
		return notify_fail("����������̫��������ʹ�á���縧�桹��\n");

	msg = CYN "$N���еĽ����һ�㼱�ٷ�����$n��\n"NOR;

	if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		target->start_busy( (int)me->query_skill("xiaofeng-sword") / 20 + 1);

		damage = damage +  2*(int)me->query_skill("xiaofeng-sword", 1);

		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/4);
		me->add("force", -damage);
		msg += HIR"ֻ��$N���еĽ�ת����ͣ,��ͬһ��������$n.\n$n��ʱ��ǰһƬ��⣬ȴ�����Լ������ѱ�������������һ�㡣\n"NOR;

		me->start_busy(2);
	} else
	{
		msg += CYN"����$p�͵������һԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->add("force", -100);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
