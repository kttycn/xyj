#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中行功？找死吗？\n");

	if ((int)me->query_skill("wuzu-xinfa", 1) < 40)
		return notify_fail("你的无祖心法修为还不够。\n");
	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 3 )
		return notify_fail("你已经非常疲劳了，只怕一运真气便有生命危险！\n");

	write( HIW "你全身放松，坐下来开始行功。\n" NOR);
	message("vision",
		HIW + me->name() + "行功一周天，缓缓呼出一口气，站了起来。脸色看起来好多了。\n" NOR,
		environment(me), me);

	me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}

