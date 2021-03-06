inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : HIM"$N看清来势，微微一晒，$w一挥，当的一
声巨响，$w蹬、蹬、蹬连退叁步 "NOR,
        "force" : 90,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "内伤",
]),
([      "action" : HIG"$N奋力一杖击地，噗地一声，穿下土中半公尺，这才紧
抓着$w稳下身来，双目瞪着$n，挥出一击。  "NOR,
         "force" : 100,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 8,
        "damage" : 65,
        "damage_type" : "内伤",
]),
([      "action" : HIB"$N双手一抡，一杖弥天盖地向着$n劈来。"NOR,
        "force" : 120,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 80,
        "damage_type" : "内伤",
]),
([      "action" : HIR"$N劈出擎天一击，$n眼看着对方的气劲随杖袭来，竟然是气势滂沱无处可躲，不愧称之为裂地 
法 "NOR,
        "force" : 350,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 100,
        "damage_type" : "内伤",
]),
([      "action" : HIY"$N瞪大双眼，劲贯全身，$w向着敌方头领斜劈挥去。  "NOR,
        "force" : 400,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 48,
        "damage" : 130,
        "damage_type" : "内伤",
]),

});


int valid_enable(string usage)
{
	return usage == "stick" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("wuzu-xinfa", 1) < 20)
                return notify_fail("你的无祖心法火候太浅。\n");
        return 1;
                
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
	int i, level;
	level   = (int) me->query_skill("liedi-stick",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "stick")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("你的体力不够，练不了裂地棍法。\n");
        me->receive_damage("kee", 20);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟裂地棍法。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟裂地棍法。\n");
	return 1;
}
