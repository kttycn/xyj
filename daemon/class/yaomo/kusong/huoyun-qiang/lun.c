#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;

int perform(object me, object target)
{
	object weapon,ob;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("���޵з���֡�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "spear")
		return notify_fail("���޵з���֡�������ǹ����ʩչ��\n");

	if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
		return notify_fail("���޵з���֡�ֻ�л��ƶ����˲ſ����ã�\n");
	if( (int)me->query_skill("huoyun-qiang", 1) < 100 )
		return notify_fail("��ġ�����ǹ��������죬����ʹ�á��޵з���֡���\n");

	if( (int)me->query("force") < 500  )
		return notify_fail("�������������\n");

	skill = me->query_skill("huoyun-qiang");
	msg = HIG "$Nǹͷһ�������еı����ֳ�����Ӱ�ӣ�����ɱ����\n"NOR;
	message_vision(msg, me, target);

	me->add("force", -100);

	msg = HIR"�����־�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	msg = HIY"�����־�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	msg = HIG"�����־�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	msg = HIR"�����־�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
	msg = HIW"�����־�����\n"NOR;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);

	me->start_busy(3);
	return 1;
}
