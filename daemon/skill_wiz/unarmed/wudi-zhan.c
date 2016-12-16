inherit SKILL;

mapping *action = ({
([      "action" : "$N˫�Ʋ�£������[ն]�־�������ϣ�������һǰһ������$n���ظ���",
        "force" : 60,
        "dodge" : -5,
        "parry" : -5,
        "damage": 10,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N���ƻ��أ�����ն���־�������ǰ���˸��뻡���͵�һ˦������$n��$l",
        "force" : 120,
        "dodge" : 10,
        "parry" : 15,
        "damage": 30,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N��������������ն���־���˫�ֶ˲������һ������������$n��ȫ��ҪѨ",
        "force" : 240,
        "dodge" : 20,
        "parry" : 20,
        "damage": 60,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N��ϥ����������ն���־���������ȭ���⣬����ֱ����ңң����$nһ��",
        "force" : 480,
        "dodge" : 40,
        "parry" : 30,
        "damage": 90,
        "lvl" : 60,
        "damage_type" : "����"
])
});

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="parry";
}

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ѧ�޵�ն������֡�\n");
	if ((int)me->query_skill("wuzu-xinfa", 1) < 10)
		return notify_fail("��������ķ���򲻹����޷�ѧ�޵�ն��\n");
	if ((int)me->query("max_force") < 100)
		return notify_fail("�������̫�����޷����޵�ն��\n");
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
		return notify_fail("�������̫���ˡ�\n");
	if ((int)me->query("force") < 20)
		return notify_fail("��������������޵�ն��\n");
	me->receive_damage("kee", 30);
	me->add("force", -10);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����޵�ն��\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����޵�ն��\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/wudi-zhan/" + action;
}
