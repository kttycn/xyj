// death dodge.幻魔步法
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	int sen;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target||!target->is_character()||!me->is_fighting(target) )
		return notify_fail("［幻魔鬼影］只能对战斗中的对手使用。\n");
	if(me->query("family/family_name") != "阎罗地府"
	&& !me->query("guild") )
		return notify_fail(HIG"「幻魔鬼影」"+NOR"是冥界不传之密！\n");

	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	if((int)me->query_skill("tonsillit",1) < 60)
		return notify_fail(HIY "「幻魔鬼影」要有高深的摄气诀作为基础，才能使用。\n" NOR);
	if( me->query_skill("ghost-steps", 1) < 80)
		return notify_fail(HIY "你的鬼影迷踪不够熟练。\n" NOR);
	if( target->is_busy() )
		return notify_fail(target->name() + "现在已经不能动弹了，还在放胆进攻吧！\n");

	lvl = (int) me->query_skill("ghost-steps", 1)/30;
	msg = HIR "$N使出鬼影迷踪步法中的绝学［幻魔鬼影］，\n$n周围出现重重鬼影，一时黑雾弥漫。" NOR;
	if(random(myexp)>yourexp/2)
	{
		message_vision(msg + "\n", me, target);
		msg = "结果$n什么都看不见了！\n";
		message_vision(msg, me, target);
		target->start_busy(lvl);
	}
	else
	{
		msg = "你失败了。\n";
		COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
		me->start_busy(2);
	}
	return 1;
}
