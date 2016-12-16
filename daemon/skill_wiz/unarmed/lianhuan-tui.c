inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N������ǰ�������ں�˫��������$n��$l����",
                "dodge":                0,
                "parry":                10,
                "force":                70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ŵ�أ����������ת�������󼲷�ɨ��Ҷ��ɨ��$n��$l",
                "dodge":                -5,
                "parry":                0,
                "force":                80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N������Σ���ϥ�����벻���ĽǶ�ײ��$n��$l",
                "dodge":                -10,
                "parry":                -5,
                "force":                90,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ҽ���գ��γ�һƬ��Ӱ�����Ǽ���$n��$lһ���߳�����",
                "dodge":                -10,
                "parry":                -5,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���Ծ���������ת��˫�Ŵ�������һǰһ�������$n��$l",
                "dodge":                0,
                "parry":                0,
                "force":                105,
                "damage_type":  "����"
        ]), 
        ([      "action":               
"$N��Ȼ���μ�ת��հ֮��ǰ��ٿ���ں�������ӰϮ��$n��$l",
                "dodge":                -5,
                "parry":                -10,
                "force":                115,
                "damage_type":  "����"
        ]),

        ([      "action":               
"$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶��£���$n��$lֱ������",
                "dodge":                10,
                "parry":                -5,
                "force":                130,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$NͻȻԾ��˫������Ȧת������糾������$n��ȫ��",
                "dodge":                10,
                "parry":                -15,
                "force":                140,
                "damage_type":  "����"
        ]), 
 
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage) { return usage=="unarmed"; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("������������ˣ���Ϣһ�������ɡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취���������ȡ�\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ���������ȡ�\n");
	return 1;
}

int effective_level() { return 10;}
 
string *parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N��$w�Ĺ�����Χ��\n",
});

string *unarmed_parry_msg = ({
        "$n����һ����˫��һ�ŵأ�ȫ����$N�Ĺ�����Χ��\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

