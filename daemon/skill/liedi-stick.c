inherit SKILL;
#include <ansi.h>

mapping *action = ({
([      "action" : HIM"$N�������ƣ�΢΢һɹ��$wһ�ӣ�����һ
�����죬$w�š��š����������� "NOR,
        "force" : 90,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 0,
        "damage" : 40,
        "damage_type" : "����",
]),
([      "action" : HIG"$N����һ�Ȼ��أ��۵�һ�����������а빫�ߣ���Ž�
ץ��$w����������˫Ŀ����$n���ӳ�һ����  "NOR,
         "force" : 100,
        "dodge" : 5,
        "parry" : -5,
        "lvl" : 8,
        "damage" : 65,
        "damage_type" : "����",
]),
([      "action" : HIB"$N˫��һ�գ�һ������ǵ�����$n������"NOR,
        "force" : 120,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 16,
        "damage" : 80,
        "damage_type" : "����",
]),
([      "action" : HIR"$N��������һ����$n�ۿ��ŶԷ�����������Ϯ������Ȼ�����������޴��ɶ㣬������֮Ϊ�ѵ� 
�� "NOR,
        "force" : 350,
        "dodge" : 5,
        "parry" : 5,
        "lvl" : 24,
        "damage" : 100,
        "damage_type" : "����",
]),
([      "action" : HIY"$N�ɴ�˫�ۣ�����ȫ��$w���ŵз�ͷ��б����ȥ��  "NOR,
        "force" : 400,
        "dodge" : -5,
        "parry" : 5,
        "lvl" : 48,
        "damage" : 130,
        "damage_type" : "����",
]),

});


int valid_enable(string usage)
{
	return usage == "stick" || usage == "parry";
}

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 500)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("wuzu-xinfa", 1) < 20)
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
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("��������������������ѵع�����\n");
        me->receive_damage("kee", 20);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����ѵع�����\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����ѵع�����\n");
	return 1;
}
