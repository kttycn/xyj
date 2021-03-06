#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : HIR "$N的藤叶突然卷向$n的$l"NOR,
    "force" : 150,
    "dodge" : 20,
    "damage_type" : "内伤",
    "lvl" : 0,
]),
([      "action" : HIR "$N的藤叶漫天盖地的卷向$n的$l"NOR,
    "force" : 300,
    "dodge" : 50,
    "damage_type" : "内伤",
    "lvl" : 12,
]),
([      "action" : HIR "$n一个措手不及，$N一下缠住了$n的$l"NOR,
    "force" : 450,
    "dodge" : 50,
    "damage_type" : "内伤",
    "lvl" : 24,
]),
});
int valid_enable(string usage)
{
	return usage=="unarmed" ||  usage=="parry";
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level = (int)me->query_skill("xueshi", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

