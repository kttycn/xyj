// unarmed.c

#include <ansi.h>

inherit SKILL;

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟扑击格斗之技。\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("你按着所学参悟扑击格斗之技。\n");
	return 1;
}

