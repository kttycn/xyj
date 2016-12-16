// wuying-sword ����Ӱ����

/*
��Ӱ��    dodge  -10    parry  -10    damage  65
�˽���Ϊ��ħ�����������ʱ��������ħ����ʱ�Ѿ������޽�ʤ�н��ľ��磬
����������������������������������ƶ���������Ϊ����Ӱ����������
���У��ֱ�Ϊ�硢�ס��硢�ơ�
*/

inherit SKILL;

mapping *action = ({
	([	"name":			"��",
		"action":
"$Nһ�����е�$w��˲��̳���ʮ������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-30,
		"parry":                -30,
		"damage":		85,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾��������е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-30,
		"parry":                -30,
		"damage":		125,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N����$w�������������⻷��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l",
		"dodge":		-30,
		"parry":                -30,
		"damage":		155,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһת������$n������$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-30,
		"parry":                -30,
		"damage":		185,
		"damage_type":		"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����Ӱ����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ��Ӱ����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ����Ӱ����\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취������Ӱ����\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ������Ӱ����\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
	return CLASS_D("wusheng") + "/wuying-sword/"+func;
}
