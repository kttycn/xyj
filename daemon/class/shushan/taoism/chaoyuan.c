#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void remove_effect(object me, int amount);
int cast(object me, object target)
{
	if(me->query("family/family_name") != "蜀山剑派" 
	&& !me->query("guild") )
        return notify_fail("你不是蜀山剑派弟子，不会用「五气朝元」。\n");

	if( (int)me->query_skill("taoism",1)<30)
		return notify_fail("你的天师仙法修为太浅，不会使用「五气朝元」。\n");

	if( (int)me->query_skill("zixia-shengong",1)<30)
		return notify_fail("你的紫霞神功修为太浅，不会使用「五气朝元」。\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("mana") < 500 )
		return notify_fail("你的法力不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	message_vision( HIW "$N化五行之气为己用，精气神立刻为之一振。\n" NOR, me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/5 );
	me->add("force", -50);
	me->add("mana", -500);
	me->set("force_factor", 0);
	me->set("mana_factor", 0);

	return 1;
}
