#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С�����ڡ���\n");
	if(!me->is_fighting())
		return notify_fail("������ڡ�ֻ����ս����ʹ�ã�\n");
	if(me->query("family/family_name")!="��ʥ��"
	&& !me->query("guild") )
		return notify_fail("������ʥ���˲���ʹ�á�����ڡ���\n");

	if((int)me->query("force") < 500 )
		return notify_fail("�������������\n");

	if((int)me->query("kee") < 300 )
		return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("fumobashi", 1) < 50)
		return notify_fail("��ķ�ħ��ʽ���𻹲�����ʹ����һ�л������ѣ�\n");

	me->delete("env/brief_message");

	message_vision(HIC"\n$N���㾫�����������˰˴����죬ͻȻ���һ����"HIR"�����"NOR+HIC"������ʱ�����ذ��������������ض���ҡ��\n"NOR, me);


	me->set_temp("fumobashi_per", 8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete_temp("fumobashi_per");

	me->receive_damage("kee", 50);
	me->add("force", -100);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	me->start_busy(2);
	return 1;
}
