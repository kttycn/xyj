//fengdao.c  「风刀」
#include <ansi.h>
#include "/daemon/skill/eff_msg.h";

inherit SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「风刀」只能对战斗中的对手使用。\n");

	if ((string)me->query("family/family_name")!="凤凰星"
	&& !me->query("guild") )
		return notify_fail("[风刀]只有凤凰星门人才能使用。\n");
	if( (int)me->query_skill("wuzu-xinfa", 1) < 100 )
		return notify_fail("你的无祖心法火候不够，使不出「风刀」。\n");

	if( (int)me->query_skill("tenglong-finger", 1) < 100 )
		return notify_fail("你的腾龙指不够熟练，不会使用「风刀」。\n");

	if( (int)me->query("force") < 1000 )
		return notify_fail("你的内力修为还不够高。\n");

	msg = HIM "$N猛然提出内息往外一散，开始聚集了四面八方的能量。\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(3);
	call_out("num1",3,me,target);
	return 1;
}

void num1(object me,object target)
{
	string msg;
msg = HIY "只见$N全身光华忽起，忽然由四面八方不断出现飘逝的光带向$N集中，$N迅速的被里入四面旋
绕的发光体之中，$n也在这些范围之内。。\n"NOR;
	message_vision(msg, me, target);
	me->start_busy(3);
	call_out("num2",3,me,target);
	return;
}

void num2(object me,object target)
{
	string msg;
	int damage;
	msg = HIG"$N忙将内息四面凝聚，集合成锋利的能量劲力，团团围住$n。\n"NOR;
	msg += HIG"$N这时不再心慈，意念一动，数百股锐利的能量光片同时迅速的向$n击去，这就是陈信独创的\n功夫之一——风刀。\n"NOR;
	message_vision(msg, me, target);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/5) {
		damage = (int)me->query_skill("tenglong-finger", 1)*2+(int)me->query_skill("wuzu-xinfa",1);
		damage = damage/2 + random(damage);
		me->add("force", -500);
		msg= HIR"数百光片在$n身上留下了十来道创痕，$n的护身真气被击散的七零八落，支撑着自己受伤的
身躯，深深吐纳着内息，这时那十来道分布腿上、手臂、胸背的伤痕才来的及慢慢的渗出血来。\n"NOR;
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/(random(3)+1));
		message_vision(msg, me, target);
	} else {
		msg = HIC"可是$p看破了$P的企图，闪在了一边。\n"NOR;
		message_vision(msg, me, target);
	}

	if(!target->is_fighting(me)) target->fight_ob(me);
	return;
}
