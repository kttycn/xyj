#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, force_wound, qi_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("kusang-bang",1);

	if( !(me->is_fighting() ))
		return notify_fail("�����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(me->query("family/family_name") != "���޵ظ�"
	&& !me->query("guild") )
		return notify_fail(HIG"�����������"+NOR"��ڤ�粻��֮�ܣ�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "stick")	     
		return notify_fail("ʹ�á����������ʱ����������Ÿ�����\n");

	if( skill < 100)
		return notify_fail("��ġ������ơ��ȼ�����, ����ʹ�á������������\n");

	if( me->query_skill("dodge",1) < 120 )
		return notify_fail("����Ṧ�������޷����á������������\n");

	msg = HIC "$NͻȻ��ͬ��������������۽�$n����ǰ���������$n���ʺ�ҧȥ��\n"NOR;
	message_vision(msg, me, target);

 	ap = me->query("combat_exp");
	dp = target->query("combat_exp") ;
	if(random(ap) > dp/2)
	{
		if(userp(me))
			me->add("force",-100);

		msg = HIG "$nֻ�����ʺ�һ���ʹ��$N���ڿ���$n����Ѫ��\n"NOR;
		force_wound = skill*2 + random(skill);
		target->add("force", -force_wound);
		target->add("kee", -force_wound);
 		me->start_busy(1+random(2));
		if( !target->is_killing(me) ) target->kill_ob(me);
	       target->set_temp("last_damage_from",me);
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�����ݣ�\n"NOR;
		if(userp(me))
			me->add("force",-100);
		me->start_busy(2);
		if( !target->is_killing(me) ) target->kill_ob(me);
	}
	message_vision(msg, me, target);
	return 1;
}

