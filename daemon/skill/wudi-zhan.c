inherit SKILL;

mapping *action = ({
([      "action" : "$N双掌并拢，运起[斩]字决和身而上，左右手一前一后劈向$n的胸腹间",
        "force" : 60,
        "dodge" : -5,
        "parry" : -5,
        "damage": 10,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左掌护胸，运起「斩」字决，右手前后划了个半弧，猛地一甩，疾劈$n的$l",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 30,
        "lvl" : 20,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形闪动，运起「斩」字决，双手端部各射出一道青气，射向$n的全身要穴",
        "force" : 240,
        "dodge" : 20,
        "parry" : 20,
        "damage": 60,
        "lvl" : 40,
        "damage_type" : "刺伤"
]),
([      "action" : "$N盘膝跌坐，运起「斩」字决，左手握拳托肘，右手直立，遥遥对着$n一劈",
        "force" : 480,
        "dodge" : 40,
        "parry" : 30,
        "damage": 90,
        "lvl" : 60,
        "damage_type" : "刺伤"
])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("学无敌斩必须空手。\n");
	if ((int)me->query_skill("wuzu-xinfa", 1) < 10)
		return notify_fail("你的无祖心法火候不够，无法学无敌斩。\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("你的内力太弱，无法练无敌斩。\n");
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
	level   = (int) me->query_skill("wudi-zhan",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("你的体力太低了。\n");
	if ((int)me->query("force") < 20)
		return notify_fail("你的内力不够练无敌斩。\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟无敌斩。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟无敌斩。\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/wudi-zhan/" + action;
}
