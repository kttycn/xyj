#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lv;
	lv = me->query_skill("moondance",1);

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("ֻ����ս����ʹ�á�����Ʈ�㡹��\n");

	if(me->query("family/family_name") != "�¹�"
	&& !me->query("guild") )
		return notify_fail("[����Ʈ��]���¹�����֮�ܣ�\n");

	if( me->query("gender") == "����")
		return notify_fail(HIY "��һ��������Ҳ��ѧ��Щ����ģ����\n" NOR);
	if((int)me->query_skill("moonforce",1) < 50)
		return notify_fail(HIY "���Բ���ķ���Ϊ������\n" NOR);
	if( lv < 80)
		return notify_fail(HIY "�����ѩ�����費��������\n" NOR);
	if((int)me->query("force") < 400)
		return notify_fail(HIY "�������������㡣\n" HIY);
	if( target->is_busy() )
		return notify_fail(target->name() + "���ڲ��ܶ�����\n");

	msg = HIY"$N��ȻһЦ����������������$n����������$n��\n"
	HIY"ʱһ�㣬$N���������ת�ţ���ʱ������һ��������Բ����\n"
	HIY"$N�����޹ǵĽ������¹�һ��������ա�\n"NOR;

	if(random(me->query("combat_exp")) > target->query("combat_exp")/2)
	{
		msg += HIW "���$p��$PΧ��ˮй��ͨ��\n" NOR;
		target->start_busy(lv/50);
		me->add("force", -100);
		me->start_busy(1);
	} else {
		msg += HIG "$pֻ��һ���������������ˡ�\n" NOR;
		me->add("force", -100);
		me->start_busy(1);
	}
	message_vision(msg, me, target);

	return 1;
}
