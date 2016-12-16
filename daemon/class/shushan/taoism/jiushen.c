//Cracked by Roath

//Ansi 99.8
//fei 2001.2
#include <ansi.h>
inherit SSERVER;
inherit F_CLEAN_UP;

int cast(object me, object target)
{
	string msg;
	object *ob;
	int i, skill, damage, spells, success_adj, damage_adj;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("你要对谁施「酒神」？\n");
	if(me->query("family/family_name") != "蜀山剑派" 
	&& !me->query("guild") )
        return notify_fail("你不是蜀山剑派弟子，不会呼唤「酒神」。\n");
	if( !me->is_fighting() )
		return notify_fail("只能在战斗中召唤酒神。\n");
	if(me->query("shushan/jiushen_cast")!=1)
		return notify_fail("你还没领会「酒神」！\n");

	if((int)me->query_skill("taoism", 1) < 150 )
		return notify_fail("你的天师仙法火候不够，哪可能呼唤出「酒神」！\n");

	if((int)me->query("mana") < 200+(int)me->query("mana_factor") )
		return notify_fail("你的法力不够，估计酒神感应不到！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你现在神智不清，连MM都不认识，更别说是酒神了！\n");

	me->add("mana", -200-(int)me->query("mana_factor"));
	me->receive_damage("sen", 100);
	me->apply_condition("drunk", 0);

	if( random(me->query("max_mana")) < 100 ) {
		message_vision(HIR "\n$N忽然一张口，朝天喷出一口酒雾\n
只见酒雾中化出一个人形，探了探头，又随酒雾消散开去！n\n"NOR, me);
		return 1;
	}

	message_vision(HIR"\n$N忽然一张口，朝天喷出一口酒雾\n只见酒雾中化出一个人形，凭空打出了一个惊雷，击向在场的每一个人！\n\n"NOR,me);
//	msg = HIR "\n$N忽然一张口，朝天喷出一口酒雾\n只见酒雾中化出一个人形，凭空打出了一个惊雷，击向在场的每一个人！\n\n"NOR;
	ob = all_inventory(environment(me));
	msg = MAG "\n        
                      《#
                      @  @_                  
                    《    @    
                     @     @    
                     _*****_   
                   《   蜀  @  
                   @         @   
                   @    山   @  
    ________________@______@_______           *****
  《_______________________________@《 iiiiii)*****  
                              ^^^^^           *****
                                           \n"NOR;

	skill = me->query_skill("spells",1);
	spells = me->query("max_mana",1);

	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || ob[i]==me ) continue;
		if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;
		damage = skill + random(skill)+spells/10 - ((int)ob[i]->query("max_mana") / 10);
		if( damage > 0 ) {
			ob[i]->receive_damage("kee", damage);
			if( (int)ob[i]->query("mana") < skill * 2 )
			ob[i]->receive_wound("kee", damage/2);
			ob[i]->apply_condition("drunk",50);
			msg += RED "结果"+ob[i]->query("name")+"被「酒神」击个正着！\n" NOR;
		}
		COMBAT_D->report_status(ob[i]);         
		if( userp(ob[i]) )
			ob[i]->fight_ob(me);
		else if( !ob[i]->is_killing(me) )
			ob[i]->kill_ob(me);
		me->kill_ob(ob[i]);
	}
	message_vision(msg, me, target);
	me->receive_wound("sen", 10);
	me->start_busy(2+random(2));
	return 1;
}

int clean_up()
{
	return 0;
}
