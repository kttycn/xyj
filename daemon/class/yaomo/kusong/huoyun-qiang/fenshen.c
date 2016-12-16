#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С��һ����?\n");
	if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
		return notify_fail("���һ����ֻ�л��ƶ����˲ſ����ã�\n");
	weapon = me->query_temp("weapon");
	if(!me->is_fighting())
		return notify_fail("���һ����ֻ����ս����ʹ��!\n");

	if((int)me->query("max_force") < 1200)
		return notify_fail("�������̫����\n");
	if((int)me->query("force") < 400 )
		return notify_fail("����������㣡\n");
	if((int)me->query_skill("huoyun-qiang", 1) < 100)
		return notify_fail("��Ļ���ǹ�ȼ�������!!\n");

	msg = HIR"\n$N���е�"+weapon->name()+""+HIR"���������ϼ,��ס$nȫ��,����һ�С��һ����!!\n"NOR;
	message_vision(msg, me, target);

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	me->set_temp("HYQ_perform", 8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("HYQ_perform");
	me->add("force", -150);
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
		}
	}

	me->start_busy(1+random(1));
	return 1;
}

