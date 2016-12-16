// SKILL zhemei-shou.c

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С����ٻ�������˫�ֺ�ӣ�ץ��$n",
        "force" : 80,
        "dodge" : 20,
        //"damage" :10,
        "lvl" : 0,
        "skill_name" : "���ٻ�Σ",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�����ǧ�������ԾȻ����ץ��$n��ͷ��",
        "force" : 100,
        "dodge" : 20,
        //"damage" : 20,
        "lvl" : 10,
        "skill_name" : "����ǧ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��ɺ�һ�֡���˫�ַ׷ɣ�$nֻ���ۻ�����",
        "force" : 90,
        "dodge" : 30,
        //"damage" : 30,
        "lvl" : 30,
        "skill_name" : "�ɺ�һ��",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С�������졹��˫�ֺϻ���$nֻ���޴��ɱ�",
        "force" : 100,
        "dodge" : 30,
        //"damage" : 45,
        "lvl" : 40,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С��׺��ױ�����˫��ƮȻץ��$n",
        "force" : 100,
        "dodge" : 30,
        //"damage" : 50,
        "lvl" : 50,
        "skill_name" : "�׺��ױ�",
        "damage_type" : "����"
]),

([      "action" : "$Nһ�С�˫���ϻ���������$n���ƺ�$n��ȫ��������",
        "force" : 150,
        "dodge" : 30,
       // "damage" : 100,
        "lvl" : 70,
        "skill_name" : "˫���ϻ�",
        "damage_type" : "����"
]),

([      "action" : "$N������Σ�����һ�ǡ��ɺ�л��������$n��ͷ��",
        "force" : 150,
        "dodge" : 30,
        //"damage" : 150,
        "lvl" : 80,
        "skill_name" : "�ɺ�л��",
           "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="unarmed" || usage=="parry"; }


mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int) me->query_skill("fox-hand",1);
if (level) {
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
   return action[0];
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("force") < 20)
                return notify_fail("������������������֡�\n");
        me->receive_damage("kee", 25);
        me->add("force", -10);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������֡�\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������֡�\n");
	return 1;
}
