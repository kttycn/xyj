//天地浑然
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
		return notify_fail("你要对谁施展这一招「天地浑然」？\n");

	if(me->query("family/family_name") != "盱眙山" 
	&& !me->query("guild") )
		return notify_fail("你是哪儿偷学来的武功，也想用「天地浑然」?\n");

	if(!me->is_fighting())
		return notify_fail("「天地浑然」只能在战斗中使用！\n");

	if((int)me->query("max_force") < 1000 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 1000 )
		return notify_fail("你的内力不足！\n");

	if((int)me->query("sen") < 500 )
		return notify_fail("你的精神不足，没法子施用外功！\n");

	weapon = me->query_temp("weapon");
	i=(int)me->query_skill("tianlong-halberd",1)+(int)me->query_skill("halberd",1);

	if( i < 150)
		return notify_fail("你的天龙戟法级别还不够，使用这一招会有困难！\n");

	extra = me->query_skill("tianlong-halberd",1) / 5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	message_vision(HIR  "\n$N错步上前，手中的"+ weapon->name() +"一式［天地浑然］，戟芒若有若无地向$n刺去！\n" NOR,me,target);

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

