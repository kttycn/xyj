// laoniupoche.c �ֻ��ȷ�����ţ�Ƴ���ʽ��Ϊ���µ�һ����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	string msg;
	int i, attack_time;
	string strr;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("����ţ�Ƴ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->query("family/family_name")!="�Ϻ�����ɽ"
	&& !me->query("guild") )
		return notify_fail("���Ƿ��ŵ��Ӳ����á���ţ�Ƴ�����\n");

	if( (int)me->query_skill("lunhui-zhang", 1) < 80 )
		return notify_fail("����ֻ��ȷ���������죬����ʹ�á���ţ�Ƴ�����һ�С�\n");
	  if((int)me->query("force") < 100 )
	       return notify_fail("����������㣡\n");

	msg = HIY "$Nʹ���ֻ��ȷ��ġ���ţ�Ƴ���һʽ��ʱ����Ȼһ�ͣ���Χһ�ж������ˡ�\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
	{
		attack_time=2+random((int)me->query_skill("lunhui-zhang",1)/30);
		if(attack_time>8)attack_time=8;
		me->add_temp("apply/attack",(int)me->query_skill("lunhui-zhang",1)/10);
		msg += CYN " ���$p��$P����ʽ��������������\n" NOR;
		message_vision(msg, me, target);
		msg = "$P�û�һ����$p����"+chinese_number(attack_time)+"��\n";
		message_vision(msg, me, target);
		for(i = 0; i < attack_time; i++)
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0, "��"+chinese_number(i+1)+"�ȡ�\n");
		me->add_temp("apply/attack",-(int)me->query_skill("lunhui-zhang",1)/10);
		me->start_busy(3);
		me->add("force", -100);
	}
	else
	{
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		me->start_busy(2);
		message_vision(msg, me, target);
	}
	return 1;
}
