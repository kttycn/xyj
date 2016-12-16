inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N���ֻ���һ��ԲȦ�������е�$wһ��",
        "$Nһ�����е�$w��һ��",
        "$N����һ�����ڿշ�����̩ɽѹ��֮ʽ���£����е�$w���ź��\n������һ��",
        "$Nһ������$w��ʹ��",
        "$N���е�$wһת��һ��",
        "$Nһ�����е�$w��һ��",
        "$N����΢�٣�һ��",
        "$N����$w�������ϼ��ӣ�һ��",  
        "$N�����������һ��",
        "$N�Ӷ�$w�������ң�һ��",                               
});

string* skill_tail =({
        "����$n��$l��ȥ",
        "�����е�$w��$n��$l�����������",
        "���ݺݻ���$n��$l",
        "��������˷�����$n��$l",
        "���ó�һƬ���⽣Ӱ������ʵʵ�Ļ���$n��$l",
        "��$w�͵�����$n��$l",
        "��$w��ƫ�����$n��̫����Ѩ",
        "��$w���˸�������$n�ĺ���",
});

mapping *action = ({
        ([      "action":               
"$N���ֻ���һ��ԲȦ�������е�$wһ�С������ķ�����$n��$l��ȥ", 
     "dodge":     10,
     "parry":     -10,
     "damage":     65,
     "damage_type":   "����"
        ]),
        ([      "action":               
"$Nһ�����е�$w��һ�С�����ɽ�ӡ������е�$w��$n��$l�����������", 
     "dodge":     0,
     "parry":     -20,
     "damage":     80,
     "damage_type":   "����"
        ]),
        ([      "action":               
"$N����һ�����ڿշ�����̩ɽѹ��֮ʽ���£����е�$w���ź������һ��"HIG"��ǧ��һ����"NOR"����$n��$l", 
     "dodge":   10,
     "parry":   -20,
     "damage":   75,
     "damage_type":   "����",
        ]),
        ([      "action":               
"$N���е�$wһת��һ�С���籩�꡹������˷�����$n��$l", 
     "dodge":   0,
     "parry":   -25,
     "damage":   80,
     "damage_type":   "����",
        ]),
        ([      "action":
"$Nһ�����е�$w��һ�С����տ������ó�һƬ���⽣Ӱ������ʵʵ�Ļ���$n��$l", 
     "dodge":   10,
     "parry":   -15,
     "damage":   60,
     "damage_type":   "����",        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("str") + (int)me->query("max_force") / 10 < 55 )
                return 
notify_fail("���������������Ҳ�����һ����������ǿ������\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="hammer") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;
        int flvl=(int)me->query_skill("force");
        int slvl=(int)me->query_skill("hammer");        

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "hammer" )
                return 
notify_fail("���������һ�������������Ƶ��������������̹ž�ʽ��\n");

        if( (int)me->query("kee") < 40
        ||      (int)me->query("force") < 4 )        
                return 
notify_fail("��������������������̹ž�ʽ����������Ϣ��Ϣ�ɡ�\n");
        me->receive_damage("kee", 40);
        if(random(slvl)>flvl)
                me->improve_skill("force", 1);        
        return 1;
} 
int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����̹ž�ʽ��\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����̹ž�ʽ��\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
 
string *parry_msg = ({
        "$n����һ����һ�С������س����͵�����$N��\n",
        "$n����΢�٣�һ�С�Χ�����ԡ�����$N�ıؾ�֮����\n",
        "$n���б����������ϼ��ӣ�һ�С���������Ŀ���$N���е�$w\n",
});

string *unarmed_parry_msg = ({
        "$nһ�С��ӹ�����������ƫ�����$N��̫����Ѩ��\n",
        "$n�Ӷ������������ң�һ�С���ɨǧ������ס��$N�Ĺ��ơ�\n",
        "$n�����������һ�С���ɳ��𡹷���$N�ĺ��ԣ��Ƶ�$N��;���С�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}


