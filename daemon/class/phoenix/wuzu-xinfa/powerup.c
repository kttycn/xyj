#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
	int skill;

	skill = me->query_skill("wuzu-xinfa",1);
	if( skill > 250 ) {
		skill=250;
	}
	if( target )
		return notify_fail("你只能提升自己的战斗力。\n");
	if( (string)me->query("family/family_name") != "凤凰星" 
	&& !me->query("guild") )
		return notify_fail("你并非凤凰城中人，不能运用狂神。\n");

	if( (int)me->query("max_force") < 500 || (int)me->query("force")<200 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经在运功中了。\n");

	me->add("force", -200);
	message_vision(HIY "$N咬紧牙关，大喝一声，爆发出无穷潜能。\n" NOR,me);
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/dodge", skill/2);
	me->set_temp("powerup", 1);

	me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/3:), skill);
	if( me->is_fighting() ) me->start_busy(2);
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("powerup");
	me->add("kee",-100);
	tell_object(me, "你忽然感到一阵虚脱。\n");
}

