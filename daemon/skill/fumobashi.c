//fumobashi ����ħ��ʽ��

/*
��ħ��ʽ    dodge  +10    parry  +10    damage  65
����ʽ������������ʦ����ħ��ʦ����������ǰ����ʽ��ǰ��ʽ���˶�����
ħ�һڣ�����ʽ�������������������������ħ�������ô˷�ħ��ʽ��ħ��
����Ϊ�ն������������١����еĵھ�ʽ�˼���ʽ������һ����ȫ������
�������������澪��أ������񣡣���
*/

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ��"HIW"��������·��"NOR"������ץ��$n�ĵ������$n�����Է���һ˲�䣬����ȴ��������$n��$l",
		"dodge":		10,
		"parry":		10,
		"force":		160,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action": "$N˫��һ������"HIB"��Ⱥ�����ס�"NOR"��˫���紩������һ�����·��ɡ�\n$n�������ۣ�ɲ�Ǽ�$N����������ǰ",
		"dodge":		5,
		"parry":		-15,
		"force":		180,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([	"action":		"ֻ��$Nһת��һָ��в�´���������$n��$l��ȴ����һ��"HIY"���콵������"NOR,
		"dodge":		5,
		"parry":		10,
		"force":		100,
		"damage_type":	"����",
                        "weapon":		"����ʳָ",
	]),
	([	"action":		"$N˫��һ������������ƶ�������һ��"HIG"���󳹴���"NOR"����һ�������$n��$l",
		"dodge":		20,
		"parry":		20,
		"force":		140,
		"damage_type":	"����",
                        "weapon":		"����", 
	]),
        ([	"action":		"$Nһ��"HIC"�����춯�ء�"NOR"�������ڿ����黮�˸��뻡������$n��$l",
		"dodge":		30,
		"parry":		10,
		"force":		70,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
        ([	"action":		"����$Nһ��ŭ�����ָ߸߾���һʽ"RED"�������ֻء�"NOR"������$n��$l",
		"dodge":		10,
		"parry":		-10,
		"force":		220,
		"damage_type":	"����",
                        "weapon":		"����",
	]),
	([	"action":		"ֻ��$Nһת��һʽ"HIM"����ɽ�ӡ�"NOR"��в�´���������$n��$l",
		"dodge":		-15,
		"parry":		10,
		"force":		300,
		"damage_type":	"����",
                        "weapon":		"����",
        ]),
        ([	"action":		"ֻ��$N���΢Ц�����ֶ�����ʹ��һʽ"HIR"���׶���ɽ��"NOR"������$n������һ��ָ��ֱ��$l����",
		"dodge":		15,
		"parry":		-5,
		"force":		320,
		"damage_type":	"����",
                        "weapon":		"����",
        ]),
	([  "action": 	HIR"$N˫��һ��������ͻ�����֮�⣬����һ�������������ɫ�������������$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                500,
                "damage_type":  "����",
	 ]),
});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��ħ��ʽ������֡�\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        int i;
        i=me->query_temp("fumobashi_per");
        if( !me->query_temp("fumobashi_per") ) {
        return action[random(8)];
        }else {
        return action[i];
        }
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ��ħ��ʽ��\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ���ħ��ʽ��\n");
        return 1;

}
int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�����ħ��ʽ��\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�����ħ��ʽ��\n");
	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("wusheng") + "/fumobashi/" + func;
}

