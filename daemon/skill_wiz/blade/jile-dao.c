inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : HIM"$N����$w�û���һ����������$nֱ����ȥ "NOR,
        "force" : 110,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : HIG"$N����һ������$w����Ȼ��������������ѹ����ȥ�������������
����â��ӳ֮�£�ԶԶ��ȥ������һ���ڶ����ڵ�������  "NOR,
         "force" : 130,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 8,
        "damage" : 65,
        "damage_type" : "����",
]),
([      "action" : HIY"$N����һ������һ��������������������ĵ�������������������
��һ��֮�£�������$n����Ѫ����"NOR,
        "force" : 150,
        "dodge" : 10,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : HIR"$NԽ��Խ���ż�����ֻӳ�һ����Ҳ���Ǻ������׵������˶��ֱ����ķ�϶��
����$n��æ���ҵظ�����  "NOR,
        "force" : 240,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 130,
        "damage_type" : "����",
]),
([      "action" : HIY"$Nʮ�ɾ���ӿ�뵶�ѣ�����һ��һ�ӣ��������������������˽��������ߣ�$n��æ��ס
�Լ���  "NOR,
        "force" : 250,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 48,
        "damage" : 200,
        "damage_type" : "����",
]),

});


int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 100)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("wuzu-xinfa", 1) < 10)
                return notify_fail("��������ķ����̫ǳ��\n");
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
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 100)
                return notify_fail("������������������˼��ֵ�����\n");
        me->receive_damage("kee", 50);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����ֵ�����\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����ֵ�����\n");
	return 1;
}

//int valid_effect(object me, object weapon, string name, int skill)
//{
//}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/jile-dao/" + action;
}
