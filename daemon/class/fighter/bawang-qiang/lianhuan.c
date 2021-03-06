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
		return notify_fail("你要攻击谁？\n");

	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("连环枪只能对战斗中的对手使用。\n");

	if(me->query("family/family_name") != "将军府" 
	&& !me->query("guild") )
		return notify_fail("你是哪儿偷学来的武功，也想用「连环枪」?\n");
	if((int)me->query("max_force") < 1000 )
		return notify_fail("你的内功太差。\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你的精神不足，没法子施用外功！\n");

	if( (int)me->query_skill("lengquan-force", 1) < 150 )//原来<100
		return notify_fail("你的冷泉心法还差些火候。\n");
	if( (int)me->query_skill("yanxing-steps", 1) < 150 )////原来<100
		return notify_fail("你的雁行步法等级太底，无法配合连环枪。\n");
	i=(int)me->query("combat_exp");
	j=(int)target->query_("combat_exp");
	k=(int)me->query_skill("bawang-qiang",1);
	if( k < 150 )//原来<100
		return notify_fail("你的霸王枪法不够娴熟，不能使用连环枪。\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIM"\n$N一挺手中"+weapon->name()+NOR+HIM"，一枪向$n刺来！\n"NOR,me,target);
	if (random(i)>random(j)) {
		damage=k+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	if (random(i)> random(j)) {
		message_vision(HIM"\n$N一枪刺出，又是一枪，刺向$n！\n"NOR,me,target);
		damage=k+random(k)+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	if (random(i)> random(j)) {
		message_vision(HIM"\n$N一枪已罢，竟不收招，又是一枪刺向$n！\n"NOR,me,target);
		damage=k+random(k)*2+(int)me->query("str")*20;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
//	if (random(2)) {
	if (random(i)> random(j)) {
		message_vision(HIM"\n$N一枪刺罢，转身又是一枪刺向$n！\n"NOR,me,target);
		damage=k+random(k)*3+(int)me->query("str")*5;//old->*20
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/5);
		COMBAT_D->do_attack(me, target, weapon);
	}
	message_vision(HIM"\n$N一枪方回，飞身跃起，又是一枪刺向$n！\n"NOR,me,target);
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
