// ���ռ���
// updated 3-1-2001 swallow

// Ϭţ���£��������ǣ��ٲ������������
// �������գ����ĸ����������ʯ������Ϣ��

#include <ansi.h>
inherit SKILL;
void throw_weapon(object,object,object,int);

mapping *action = ({
	([  "action": 
"$N��Ȼ������Х����Ծ�ڿգ�ȡ�����ҡ�\nֻ�������촦��$w�ѵ�$n��磬�ۿ���Ҫ�Դ�������\n���С������ʯ����Ȼ�д�ʯ֮��",
		"damage": 75,
		"dodge" : -20,
		"parry" : 10,
		"damage_type": "����",
		"post_action": (: throw_weapon :),
		"name":      "�����ʯ"
	]),
	([  "action":
"$N�������󣬸���һ�С����ĸ�������$w�Ѵ���Х����$nǰ�ط�ȥ",
		"damage":   85,
		"dodge":   20,
		"parry":   20,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "���ĸ���"
	]),
	([  "action":
"ͻȻ�䣬$N�����������ȥ������$n����֮�⡣\n$n����׷����$N��Ȼת����һ�����ٲ������\n$w�Ѵ����ƿ�֮����ֱ��$n����",
		"damage":   70,
		"dodge":       -10,
		"parry":       -10,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "�ٲ�����"
	]),
	([  "action":
"$N������������׼$n��������һ����\n$n�������ܣ�ͻȻ���ֲ�����������������޴���ȥʱ��\n$N�乭�����ֻ��һ֧$w��$n��$l���ɶ���",
		"damage":   75,
		"dodge":       -20,
		"parry":   10,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "��������"
    ]),
	([  "action":
"$N��ָ΢����$nֻ������ಡ���һ����$w�ѵ�$lǰ���硣\n$nû�ŵ����С��������ա��������֮�죬���������޴�",
		"damage":   90,
		"dodge":   10,
		"parry":       -10,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "��������"
	]),
	([  "action":
"$N��վ�ȣ�����͸�������Ĺ������£�һ�С����Ǹ��¡���$w��һ�����$n��$l",
		"damage":   75,
		"dodge":   20,
		"parry":   20,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "���Ǹ���"
    ]),
	([  "action":
"$NͻȻ����һֹ������ȣ�һ���֣�$w��$n��ȥ��\nֻ��$n����������������Ĺ�Ӱ��ȴ������һ˿������",
		"damage":   90,
		"dodge":   20,
		"parry":   20,
		"damage_type":   "����",
		"post_action":   (: throw_weapon :),
		"name":     "����Ϣ��"
    ]),
	([  "action":
"$n��������������һ����$N������Ҫ���ܣ�ͻȻŤ������\nһ�С�Ϭţ���¡�������$w��ͬ����һ�㣬ֱ����$n��$l",
		"damage":       80,
		"dodge":       -10,
		"parry":       -10,
		"damage_type":  "����",
		"post_action":  (: throw_weapon :),
		"name":       "Ϭţ����"
	]),
});
 
int valid_learn(object me)
{
	object ob;

	if(me->query_skill("archery",1) < 20)
		return notify_fail("��Ĺ������죬�����ڼ�ս���ϼ�������У�\n");
	if( (int)me->query("max_force") < 1000 )
		return notify_fail("������������������������\n");
	if( !(ob=me->query_temp("weapon")) || !(ob=me->query_temp("secondary_weapon")) )
		return notify_fail("�����޹�����������ʦ�����̣�\n");
	return 1;
}

mapping query_action(object me)
{
	int max;

	if (!me) me = this_object();
		max=me->query_skill("luori-archery",1) / 15;
	if (max>sizeof(action)) max=sizeof(action);
		return action[random(max)];
}

string learning_message(int level)
{
	if (level / 15 >= sizeof(action) ) return "";
	else return "�ԡ�" + action[level/15]["name"] + "��������������";
}

int valid_enable(string usage)
{
	return usage=="archery" || usage=="parry";
}

int practice_skill(object me)
{
	object weapon,weapon2;

	if( !objectp(weapon = me->query_temp("weapon"))
	|| !objectp(weapon2 = me->query_temp("secondary_weapon")) )
		return notify_fail("û�й��������׼ͷ��\n");

	if( (int)me->query("kee") < 40 || (int)me->query("force") < 10)
		return notify_fail("����������㣬����������\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$N�乭�����һ�����к��ģ�");
	(: throw_weapon :);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취�������������\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ�������������\n");
	return 1;
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
	if( objectp(weapon) ) {
		if( (int)weapon->query_amount()==1 ) {
			weapon->unequip();
			tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n");
		}
		weapon->add_amount(-1);
	}
}

string perform_action_file(string func)
{
	return CLASS_D("moon") + "/luori-archery/" + func;
}
