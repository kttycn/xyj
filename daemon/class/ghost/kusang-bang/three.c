#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, j;

	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("你要对谁施展这一招「神·人·鬼」？\n");
	if(me->query("family/family_name") != "阎罗地府"
	&& !me->query("guild") )
		return notify_fail(HIG"「神·人·鬼」"+NOR"是冥界不传之密！\n");
	if( !me->is_fighting() )
		return notify_fail("「神·人·鬼」只能在战斗中使用。\n");

	if((int)me->query("force") < 1000 )
		return notify_fail("你的内力不足！\n");

	if((int)me->query("kee") < 300 )
		return notify_fail("你的精神不足，没法子施用外功！\n");

	if(((int)me->query_skill("kusang-bang", 1) < 50)
		||((int)me->query_skill("zhuihun-sword",1) <50)
		||((int)me->query_skill("hellfire-whip",1) <50))
		return notify_fail("你的功夫级别还不够，使用这一招「神·人·鬼」会有困难！\n");

	weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}
	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision("\n$N将手中的棒子轮个大圆，借着天空的雷鸣电闪，祭出了「神·人·鬼」三招！\n"NOR,me,target);
    me->set_temp("HellZhen", 7);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    me->set_temp("HellZhen", 6);  
    COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

    me->set_temp("HellZhen", 5);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    me->delete_temp("HellZhen");

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);

    me->receive_damage("kee", 150);
    me->add("force", -100);

    if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(3);
	return 1;
}
