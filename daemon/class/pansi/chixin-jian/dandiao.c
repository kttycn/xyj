// dandiao.c 形影单吊

#include <ansi.h>
#include <skill.h>
#include <weapon.h>

inherit SSERVER;
void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("形影单吊只能对战斗中的对手使用。\n");

     if(me->query("family/family_name")!="盘丝洞"
	&& !me->query("guild") )
           return notify_fail("“形影单吊”只有盘丝洞门人才可以用！\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("chixin-jian", 1) < 40 )
		return notify_fail("你的痴心情长剑法不够娴熟，不会使用「形影单吊」。\n");
	
	if( (int)me->query_skill("jiuyin-xinjing", 1) < 40 )
		return notify_fail("你的九阴心经不够娴熟，不会使用「形影单吊」。\n");
	
	if( (int)me->query("force") < 300  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("dandiao_wu") ) 
		return notify_fail("你已经在运功中了。\n");

	msg = MAG"$N双手握起" + weapon->name() + MAG"，剑芒暴长，一式「形影单吊」，驭剑猛烈绝伦地往$n冲刺！\n"NOR;
	message_vision(msg, me, target);

	skill = (int)me->query_skill("chixin-jian",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);

	me->set_temp("CXJ_perform", 15);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("CXJ_perform");

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), 20);
	me->add("force", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("dandiao_wu");
	tell_object(me, "你的形影单吊运行完毕。\n");
}
