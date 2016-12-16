#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j,k,damage;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ����˭��\n");

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("����ǹֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(me->query("family/family_name") != "������" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�����ǹ��?\n");
	if((int)me->query("max_force") < 1000 )
		return notify_fail("����ڹ�̫�\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if( (int)me->query_skill("lengquan-force", 1) < 150 )//ԭ��<100
		return notify_fail("�����Ȫ�ķ�����Щ���\n");
	if( (int)me->query_skill("yanxing-steps", 1) < 150 )////ԭ��<100
		return notify_fail("������в����ȼ�̫�ף��޷��������ǹ��\n");
	i=(int)me->query("combat_exp");
	j=(int)target->query_("combat_exp");
	k=(int)me->query_skill("bawang-qiang",1);
	if( k < 150 )//ԭ��<100
		return notify_fail("��İ���ǹ��������죬����ʹ������ǹ��\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIM"\n$Nһͦ����"+weapon->name()+NOR+HIM"��һǹ��$n������\n"NOR,me,target);
	if (random(i)>random(j)) {
		damage=k+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	if (random(i)> random(j)) {
		message_vision(HIM"\n$Nһǹ�̳�������һǹ������$n��\n"NOR,me,target);
		damage=k+random(k)+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	if (random(i)> random(j)) {
		message_vision(HIM"\n$Nһǹ�Ѱգ��������У�����һǹ����$n��\n"NOR,me,target);
		damage=k+random(k)*2+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
//	if (random(2)) {
	if (random(i)> random(j)) {
		message_vision(HIM"\n$Nһǹ�̰գ�ת������һǹ����$n��\n"NOR,me,target);
		damage=k+random(k)*3+(int)me->query("str")*5;//old->*20
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	message_vision(HIM"\n$Nһǹ���أ�����Ծ������һǹ����$n��\n"NOR,me,target);
	damage=k+random(k)*4+(int)me->query("str")*5;//old->*20
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/5);
	COMBAT_D->do_attack(me, target, weapon);

	me->receive_damage("sen", 50);
	me->add("force", -100-(int)me->query("force_factor"));
	me->receive_damage("kee", 30); 
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(5);
	return 5;
}
