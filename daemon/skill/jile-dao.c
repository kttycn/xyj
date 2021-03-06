inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : HIM"$N手中$w幻化做一条巨龙，朝$n直奔而去 "NOR,
        "force" : 110,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "割伤",
]),
([      "action" : HIG"$N功力一摧手中$w，居然青光大作，将银光压了下去，而在特殊的线
条光芒掩映之下，远远望去，正如一条摆动飞腾的青龙。  "NOR,
         "force" : 130,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 65,
        "damage_type" : "割伤",
]),
([      "action" : HIY"$N劈出一刀，这一刀，刀长加上向外延伸的刀气，威力将近两公尺
，一挥之下，当场将$n劈得血肉横飞"NOR,
        "force" : 150,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 100,
        "damage_type" : "割伤",
]),
([      "action" : HIR"$N越来越滑溜，偶尔随手挥出一刀，也总是毫无徵兆地钻入了对手兵器的缝隙中
，让$n手忙脚乱地格档闪避  "NOR,
        "force" : 240,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 130,
        "damage_type" : "割伤",
]),
([      "action" : HIY"$N十成劲力涌入刀把，向下一旋一挥，青龙闪出，刀气延伸了将近两公尺，$n连忙护住
自己。  "NOR,
        "force" : 250,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 48,
        "damage" : 200,
        "damage_type" : "割伤",
]),

});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力不够。\n");
        if ((int)me->query_skill("wuzu-xinfa", 1) < 10)
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
        level   = (int) me->query_skill("jile-dao",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("kee") < 100)
                return notify_fail("你的体力不够，练不了极乐刀法。\n");
        me->receive_damage("kee", 50);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("你的内力、精神或气不够，没有办法参悟极乐刀法。\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("你按着所学参悟极乐刀法。\n");
	return 1;
}

//int valid_effect(object me, object weapon, string name, int skill)
//{
//}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/jile-dao/" + action;
}
