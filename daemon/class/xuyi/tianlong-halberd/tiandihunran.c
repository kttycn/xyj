//��ػ�Ȼ
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int extra, i;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С���ػ�Ȼ����\n");

	if(me->query("family/family_name") != "����ɽ" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á���ػ�Ȼ��?\n");

	if(!me->is_fighting())
		return notify_fail("����ػ�Ȼ��ֻ����ս����ʹ�ã�\n");

	if((int)me->query("max_force") < 1000 )
		return notify_fail("�������������\n");

	if((int)me->query("force") < 1000 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 500 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	weapon = me->query_temp("weapon");
	i=(int)me->query_skill("tianlong-halberd",1)+(int)me->query_skill("halberd",1);

	if( i < 150)
		return notify_fail("�������ꪷ����𻹲�����ʹ����һ�л������ѣ�\n");

	extra = me->query_skill("tianlong-halberd",1) / 5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	message_vision(HIR  "\n$N����ǰ�����е�"+ weapon->name() +"һʽ����ػ�Ȼ�ݣ��â�������޵���$n��ȥ��\n" NOR,me,target);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	me->set_temp("TLJ_perform", 6);
	COMBAT_D->do_attack(me, target, weapon);

	me->delete_temp("TLJ_perform");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

	me->receive_damage("sen", 50+random(100));
	me->add("force", -200);

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	me->start_busy(2);
	return 1;
}

