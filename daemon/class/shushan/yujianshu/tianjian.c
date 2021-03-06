//zhanlong.c 斩龙诀
#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
	object weapon;
	int i,j,damage,p;
	string msg;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("你要对谁使用［斩龙诀］？\n");

	if(!me->is_fighting())
		return notify_fail("你们没有在打架！\n");

	if(me->query("family/family_name")!="蜀山剑派"
	&& !me->query("guild") )
		return notify_fail("不是蜀山的不能用「斩龙诀」！\n");

	if((int)me->query("max_force") < 400 )
		return notify_fail("你的内功太差。\n");
	if((int)me->query("force") < 200 )
		return notify_fail("你的内力不足！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你的精神不足，没法子施用外功！\n");
	if((int)me->query_skill("taoism", 1) < 50)
		return notify_fail("你的天师仙法等级不够，不能使用［斩龙诀］！\n");
	i=(int)me->query_skill("yujianshu",1);
	j=(int)target->query_skill("dodge",1);
	if(i<75)        
		return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIW"\n$N口中念动《道德经》真言："NOR,me,target);
	message_vision(HIW"\n挫其锐，解其纷，和其光，同其尘"NOR,me,target);
	message_vision(HIW"\n手中剑光一闪，掠向$n。。。",me,target);
	if (random((int)me->query("combat_exp"))>(int)target->query("combat_exp")/3) {
//		message_vision(HIR"\n\n$n身体微微一晃，面色苍白了许多\n"NOR,me,target);
		damage=i+random(i);
		target->add("force",-damage);
		target->receive_damage("sen",damage);
		p = (int)target->query("sen")*100/(int)target->query("max_sen");
		msg = HIR"\n\n"+damage_msg(damage, "震伤")+NOR;
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		if ((int)target->query("force")<0) target->set("force",0);
		else target->add("force", -random(damage));
		if ((int)target->query("mana")<0) target->set("mana",0);
		else target->add("mana",-random(damage));
		if ((int)me->query("force")<0) me->set("force",0);
		me->receive_damage("sen", 100);
		message_vision(msg,me,target);
	}
	else {
		message_vision(YEL"\n$n身体只是微微一晃，仿佛无甚大碍\n"NOR,me,target);
	}
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(2);
	return 1;
}
