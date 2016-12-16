
#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
	string msg;
	object weapon, target;
	int skill, ap, dp, force_wound, kee_wound;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("tianyi-zhen",1);

	if( !(me->is_fighting() ))
		return notify_fail("��ն��ɱ����ֻ����ս�������ڶ������ϡ�\n");

	if(me->query("family/family_name") != "��ԯ��Ĺ"
	&& !me->query("guild") )
		return notify_fail("�㲻����ԯ��Ĺ���ӣ�����ʹ��[ն��ɱ��]��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "needle")

	if( skill < 70)
		return notify_fail("�����һ���벻������, ����ʹ�á�ն��ɱ������\n");

	if( me->query("force") < 150 )
		return notify_fail("��������������޷����á�ն��ɱ������\n");

	msg = HIY "$N��ָ�뵶��ָ��������ö����,Ǳ��������һʽ��ն��ɱ������ֱ��
$n���ϡ��С��µ����ȥ��\n";
	message_vision(msg, me, target);

	ap = me->query_skill("needle",1) + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-100);
		msg = "$Nһ�С�ն��ɱ�������ж��֣�$nֻ���������򱻴���һ��\n";
		msg += "ȫ����Ѫ�ͷ����ţ�\n" NOR;


		force_wound = 500 + random(skill);
		if(force_wound > target->query("force"))
			force_wound = target->query("force");

		kee_wound = force_wound / 5;
		if(kee_wound > target->query("kee"))
			kee_wound = target->query("kee");

		target->add("force", -force_wound);
		target->add("kee", -kee_wound);
		target->add("eff_kee", -kee_wound);
		target->start_busy(2);
	      me->start_busy(random(2));
	}
	else
	{
		if(userp(me))
			me->add("force",-80);
		msg = "����$n����һ�����������������һ�С�\n"NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);

	return 1;
}
