//staff.c yushu-2000.10.30
//2000.10

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
	int skill_sanqing, skill_sword, skill_force,attack_amount,dodge_amount,skill_dodge;

	skill_dodge=me->query_skill("dodge",1);

	if(	!me->is_fighting())
		return notify_fail("「化剑为杖」只有在战斗中才能使用。\n");

	if(me->query("family/family_name") != "五庄观"
	&& !me->query("guild") )
		return notify_fail("[化剑为杖]是五庄观不传之密！\n");
	skill_sanqing = me->query_skill("sanqing-jian",1);
	if (skill_sanqing<80)
		return notify_fail("你三清剑法等级还不够。\n");

	if (me->query_skill_mapped("force")!="zhenyuan-force")
		return notify_fail("「化剑为杖」必须配合镇元神功才能使用。\n");

	if((int)me->query_skill("fumo-zhang", 1) < 80)
		return notify_fail("你的伏魔杖级别还不够，使用这一招会有困难！\n");

	skill_force=me->query_skill("zhenyuan-force",1);
	if (skill_force<40)
		return notify_fail("你的镇元神功不够纯熟。\n");

	skill_sword=me->query_skill("sword",1);
	if (skill_sword<40) 
		return notify_fail("你的基本剑术太差劲了。\n"); 

	if( (int)me->query("force") < 50 )      
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("powerup") )
		return notify_fail("你已经化剑为杖了。\n");

	me->add("force", -50);
	message_vision(
		HIY"$N招式一转，手中剑越舞越快，化剑为杖，怪招迭出。\n" NOR, me);

	attack_amount=skill_sanqing/2;					//added by vikee . hmm... perhaps the 
		                                                //the damage is wrong.you can modify it
		                                                //as your wish.
	dodge_amount=skill_dodge*random(6)/10;

	me->add_temp("apply/damage",attack_amount);  
	me->add_temp("apply/dodge",-dodge_amount);      //use this perform ,reduce your effect dodge :P added by vikee
	me->set_temp("powerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", 
	me,dodge_amount,attack_amount:), skill_sanqing/20);

	return 1;
}
 
void remove_effect(object me, int dodge_amount,int attack_amount)
{
	me->add_temp("apply/damage", -attack_amount);
	me->add_temp("apply/dodge",dodge_amount);
	me->delete_temp("powerup");
	message_vision(
	HIY"$N深吸了一口气,收起招式.\n"NOR,me);
}

