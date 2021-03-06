#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
	int damage;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「光球」只能对战斗中的对手使用。\n");

	if ((string)me->query("family/family_name")!="凤凰星"
	&& !me->query("guild") )
		return notify_fail("[光球]只有凤凰星门人才能使用。\n");

	if( (int)me->query_skill("wuzu-xinfa", 1) < 50 )
		return notify_fail("你的无祖心法火候不够，使不出「光球」。\n");

	if( (int)me->query_skill("tenglong-finger", 1) < 40 )
		return notify_fail("你的腾龙指不够熟练，不会使用光球」。\n");

	if( (int)me->query("force") < 600 )
		return notify_fail("你的内力不够。\n");

    msg = HIM "
$N将全身每个气海光球各涌出三分之一，分为两道纳入两条手臂中，。\n"NOR+HIY"
眼看劲力逐渐凝聚，身旁的气劲却越旋越快，回旋的劲力与$N护身的气劲碰触到，直是
嘎然作响，忽然同时轰然的爆裂开来，两道粗大凝结如实物一般的光束，撕裂空间般的
往$n狂奔而去。。\n"NOR;
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
		me->start_busy(5);
		damage = (int)me->query_skill("yinyang-zhang", 1)*2+(int)me->query_skill("wuzu-xinfa",1);
		damage = damage/3 + random(damage);
		msg += HIR"
能量相击之下，$n马上被$N狂龙一般的内劲瞬间吞噬，两股光柱轰然 的击到了$n的身上。\n"NOR;
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/(random(3)+1));
		me->add("force", -400);
	} else {
		me->start_busy(3);
		msg += HIC"可是$p看破了$P的企图，闪在了一边。\n"NOR;
	}
	message_vision(msg, me, target);

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}

