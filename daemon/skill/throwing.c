// throwing.c

inherit SKILL;

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟暗器使用。\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("你按着所学参悟暗器使用。\n");
	return 1;
}
