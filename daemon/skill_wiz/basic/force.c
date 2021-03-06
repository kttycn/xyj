// force.c

#include <ansi.h>

inherit SKILL;

int valid_learn(object me) { return 1; }

string exert_function_file(string func)
{
        return "/daemon/class/force/" + func;
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "若有若无" NOR,
		HIB "初窥门径" NOR,
		HIY "渐入佳境" NOR,
		HIB "气息悠长" NOR,
		YEL "生生不绝" NOR,
		YEL "英华内敛" NOR,
		YEL "通关在即" NOR,
		CYN "豁然贯通" NOR,
		HIC "举世无双" NOR,
		HIC "震古铄今" NOR,
		HIW "返璞归真" NOR,
		HIW "深不可测" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟基本内功。\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("你按着所学参悟基本内功。\n");
	return 1;
}
