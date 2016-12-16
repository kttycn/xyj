// tenglong-finger.c ��������ָ

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([     "action" : HIM"$N�������죬˫���˳��˳ɸվ���������һ�ϣ���������������һѹһ�ţ�����������������������������$N���֣���ʱ��$nǰ���������ڼ���"NOR,
        "force" : 10,
       "dodge" : 10,
        "parry" : 10,
       "damage" :100,
       "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : HIW"$N����һ�һ�Ƹա�һ���ᣬ����������������$nֱ���˳�ȥ����"NOR,
        "force" : 20,
       "dodge" : 10,
        "parry"    :   5,
            "damage" : 140,
        "lvl" : 10,
        "damage_type" : "����"
]),
([      "action" : HIG"$N����һ����������������������壬���־�����Ȼδ���ں�Ϊһ�������õ����ɾ����м�ķ�϶���룬ȴ��$n�ڰ���м���������"NOR,
        "force" : 40,
        "dodge" : -5,
        "parry"    :   10,
        "damage" : 180,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : HIC"$N˫��һȦ�������������������������˫�Ʊ��ڶ�����$n��Ȼ��֪��˫�ƾ���ӭ�� ����������������һ�ӣ�����һ�ƻ��գ����ܿ��Ƶ���ת����"NOR,
        "force" : 60,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 200,
        "lvl" : 30,
        "damage_type" : "����"
]),
([      "action" : HIY"$N˫��һ����ȫ������һ�ͣ��������������������ƿն��ϣ���ʱ���������Ѿ���������������Ȼһ�����죬ը��$n"NOR,
        "force" : 80,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 220,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : HIB"$N��������������Ȼ��������ѭһ�Ʊ��ڶ�����ͬʱ��˫������һ�ۣ�����һ�Ӵ����漴��ʼ��������������$n"NOR,
        "force" : 100,
        "dodge" : 15,
        "parry" : 15,
        "damage" :230,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : HIR"$N�����ת��һ�����������ˣ�һ������ȫ���Ƴ���������Ӱɢ�����֣����ε���ס$n"NOR,
        "force" : 120,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 290,
        "lvl" : 80,
        "damage_type" : "����"
]),
([     "action" : HIM"$Nŭ�����һ����ʮָͬ�ֹ⻪������ָ������ɢ��$nȴ������һƬ����֯�ɵĹ�������æ��Хһ���������Ϸ�"NOR,
        "force" : 140,
       "dodge" : 10,
        "parry" : 10,
       "damage" :320,
       "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : HIW"$N��������ָͻ����һ��������ʳָ�����ֱ��$n��$l"NOR,
        "force" : 160,
       "dodge" : 10,
        "parry"    :   5,
            "damage" : 340,
        "lvl" : 120,
        "damage_type" : "����"
]),
([      "action" : HIG"$N����ָ����������һ����״�⻪ת�۷���ʮ���ߣ�����$n�Ķ�ͷ"NOR,
        "force" : 180,
        "dodge" : -5,
        "parry"    :   10,
        "damage" : 380,
        "lvl" : 140,
        "damage_type" : "����"
]),
([      "action" : HIC"$N�����ָ���˵��⻪��ͷ��������$n�ľ�����ɢ"NOR,
        "force" : 200,
        "dodge" : 5,
        "parry" : 5,
        "damage" : 400,
        "lvl" : 160,
        "damage_type" : "����"
]),
([      "action" : HIY"$N����ָһ�������װ��������֮����һ������������������$n��ȥ"NOR,
        "force" : 220,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 420,
        "lvl" : 180,
        "damage_type" : "����"
]),
([      "action" : HIB"$Nƽ��Լ����ޥȻ����һ�һ��������������һ�����$nֱӭ��ȥ���������������һ�񴮵��������������ϴ���"NOR,
        "force" : 240,
        "dodge" : 15,
        "parry" : 15,
        "damage" :440,
        "lvl" : 200,
        "damage_type" : "����"
]),
([      "action" : HIR"$N���ƺ�Ȼ�Ŵ�һ������������ɫ��һ��һ�µĵ�����ǰ���㶥һ����ֻ������һ���������ǹɵ�����Ϣ������ɢ"NOR,
        "force" : 300,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 500,
        "lvl" : 250,
        "damage_type" : "����"
]),
});


int valid_enable(string usage)
{
	return usage == "unarmed" || usage == "parry";
}

int valid_learn(object me)
{
	if ((int)me->query("max_force") < 500)
		return notify_fail("�����Ϣ������\n");
	if ((int)me->query_skill("wuzu-xinfa", 1) < 80)
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
	level   = (int) me->query_skill("tenglong-finger",1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ָ������������\n");
	if (((int)me->query("kee") < 100) || (int)me->query("sen")<60)
		return notify_fail("�����������������ָ��\n");
	me->receive_damage("kee", random(80));
	me->receive_damage("sen", random(40));
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������ָ��\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������ָ��\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("phoenix") + "/tenglong-finger/" + action;
}


