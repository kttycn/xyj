// huitian-shenjue 【回天神决】

/*
回天神决
引动三界灵气集于一身为己用，当练到第九重的时候，可以引动天地灵
气，使用一招“天惊地变”引是借助”天“的力量，引动九天之气使出，威
力足可摧天毁地，在场所有人无一幸免！
*/

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("回天神决只能读【回天神鉴】，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
	return CLASS_D("wusheng") + "/xiantian-force/" + func;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else if ( level < 290 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return BLU "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 5 )
		return HIB "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 7 )
		return YEL "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 9 )
		return CYN "第"+chinese_number( stage(level) )+"重　" NOR;
	else 
		return HIW "第"+chinese_number( stage(level) )+"重　" NOR;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 90
	|| (int)me->query("sen") < 90 
	|| (int)me->query("force") < 20 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟回天神决。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟回天神决。\n");
	return 1;
}
string exert_function_file(string func)
{
        return CLASS_D("force") + "/huitian-shenjue/" + func;
}
