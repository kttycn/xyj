
//vikee 
//pili.c you can add it to the directory /daemon/class/puti/qianjun-bang/
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void pili_ok(object);
int perform(object me, object target)
{
	object weapon;
		
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展这一招「霹雳三打」？\n");

	if(me->query("family/family_name") != "方寸山三星洞" 
	&& !me->query("guild") )
		return notify_fail("你是哪儿偷学来的武功，也想用「霹雳三打」?\n");
	if(!me->is_fighting())
		return notify_fail("「霹雳三打」只能在战斗中使用！\n");

	if((int)me->query("max_force") < 500 )
		return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

	if((int)me->query("sen") < 500 )
		return notify_fail("你的精神不足，没法子施用外功！\n");

	if((int)me->query_skill("qianjun-bang", 1) < 100)
		return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");

	if(me->query_temp("no_pili"))
		return notify_fail("绝招滥使就不灵了！\n");
	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N运足精神，身形一转，霹雳间连续向$n攻出了三招！\n"NOR,me,target);

	me->set_temp("QJB_perform", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set_temp("QJB_perform", 1);  
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	me->set_temp("QJB_perform", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete_temp("QJB_perform");

	me->receive_damage("sen", 100);
	me->add("force", -100);
	me->set_temp("no_pili",1);
		call_out("pili_ok",2+random(2),me);


	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	return 1;
}

void pili_ok(object me)
{
	if (!me) return;
	me->delete_temp("no_pili");
}	 
