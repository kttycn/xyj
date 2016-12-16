#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : HIR "$N����ҶͻȻ����$n��$l"NOR,
    "force" : 150,
    "dodge" : 20,
    "damage_type" : "����",
    "lvl" : 0,
]),
([      "action" : HIR "$N����Ҷ����ǵصľ���$n��$l"NOR,
    "force" : 300,
    "dodge" : 50,
    "damage_type" : "����",
    "lvl" : 12,
]),
([      "action" : HIR "$nһ�����ֲ�����$Nһ�²�ס��$n��$l"NOR,
    "force" : 450,
    "dodge" : 50,
    "damage_type" : "����",
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

