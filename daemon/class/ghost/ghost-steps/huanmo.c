// death dodge.��ħ����
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	int sen;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("�ۻ�ħ��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->query("family/family_name") != "���޵ظ�"
	&& !me->query("guild") )
		return notify_fail(HIG"����ħ��Ӱ��"+NOR"��ڤ�粻��֮�ܣ�\n");

	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	if((int)me->query_skill("tonsillit",1) < 60)
		return notify_fail(HIY "����ħ��Ӱ��Ҫ�и������������Ϊ����������ʹ�á�\n" NOR);
	if( me->query_skill("ghost-steps", 1) < 80)
		return notify_fail(HIY "��Ĺ�Ӱ���ٲ���������\n" NOR);
	if( target->is_busy() )
		return notify_fail(target->name() + "�����Ѿ����ܶ����ˣ����ڷŵ������ɣ�\n");

	lvl = (int) me->query_skill("ghost-steps", 1)/30;
	msg = HIR "$Nʹ����Ӱ���ٲ����еľ�ѧ�ۻ�ħ��Ӱ�ݣ�\n$n��Χ�������ع�Ӱ��һʱ����������" NOR;
	if(random(myexp)>yourexp/2)
	{
		message_vision(msg + "\n", me, target);
		msg = "���$nʲô���������ˣ�\n";
		message_vision(msg, me, target);
		target->start_busy(lvl);
	}
	else
	{
		msg = "��ʧ���ˡ�\n";
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		me->start_busy(2);
	}
	return 1;
}
