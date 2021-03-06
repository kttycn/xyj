#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp, yourexp;
	object weapon;    
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("百鸟争鸣只能在战斗中使用.\n");
	if(me->query("family/family_name")!="大雪山"
	&& !me->query("guild") )
		return notify_fail("“百鸟争鸣”只有大雪山门人才可以用！\n");

	weapon = me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，不能使用百鸟争鸣！\n");
	if( (int)me->query_skill("bainiao-jian",1) < 80)
		return notify_fail("你的百鸟剑法等级还不够!\n");
	if( (int)me->query_skill("ningxue-force",1) < 80)
		return notify_fail("你的冰谷凝血功还不够纯熟.\n");
	if( (int)me->query("max_force") < 800)
		return notify_fail("你的内力太弱了!\n");
	if( (int)me->query("force") < 400)
		return notify_fail("你的内力不够了.\n");;
	myexp = (int)me->query("combat_exp")/1000*(int)me->query_skill("sword");
	yourexp = (int)target->query("combat_exp")/1000*(int)target->query_skill("dodge");
	msg = HIC"$N长剑一振,忽然发出一阵悦耳的乐声,细听那乐声,平和中正,清新典雅.\n"
"这乐声绝不沾半分妖邪之气,正是上古神曲---百鸟争鸣!!\n" NOR;;
	if( random(myexp*3) > yourexp)
	{
		msg += HIG"$n听得入了神,将身旁的敌人搁在一边.\n" NOR;
		target->start_busy(3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		msg += HBYEL"$N却剑交左手,剑尖从一极刁的角度刺来,极尽毒,阴,狠,辣之能事.与曲中意境大异其趣!\n" NOR;
		me->start_busy(1);
		me->add("force",-200);
	}
	else
	{
		msg += HIY"$n似乎对你的乐声不感兴趣，轻轻地避在一旁。\n" NOR;
		me->start_busy(3);
		me->add("force",-150);  
	}
	message_vision(msg, me, target);
	return 1;
}
