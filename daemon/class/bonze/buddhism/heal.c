inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
	int mymana=me->query("mana"), cost=200, cure,spell;
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢，过会儿再念咒吧！\n");
	spell=me->query_skill("spells")/2 + me->query_skill("buddhism");
	if(spell < 40)
		return notify_fail("你的大乘佛法有效等级还不够。\n"); //enable buddhism > 40

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("你精神实在不济，只怕一运法力便有生命危险！\n");
    
	if( mymana ) < 50)
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < 50 )
		return notify_fail("你的精神无法集中！\n");

	message_vision(HIW"$N喃喃念了几句咒语，盘膝坐下，开始神游外物。\n"NOR, me);
  
	cure=10 + (int)me->query_skill("spells")/5;
	if (me->query("eff_sen") < me->query("max_sen"))
	{
		if (cure > (me->query("max_sen") - me->query("eff_sen")))
			cure = me->query("max_sen") - me->query("eff_sen");
	}
	else cure=0;

	me->receive_curing("sen", cure);
    me->add("mana", -cost);
	return 1;
}

