// perception.c
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "贼头贼脑" NOR,     
		HIB "贼手贼脚" NOR,
		HIB "快手快脚" NOR,     
		CYN "出手如风" NOR,
		HIC "手到擒来" NOR,     
		HIW "妙手神偷" NOR,
	});

	grade = level / 10;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟偷技。\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("你按着所学参悟偷技。\n");
	return 1;
}
