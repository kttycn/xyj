// jindouyun.c

inherit SKILL;

string *dodge_msg = ({
	"$n���˷�������ǰ̤��һ�����Ƶ�$N��;���С�\n",
	"$n���һ�����ҿ�һ����һʱ����Ӱ�ƺ��������������$N�ε��ۻ����ҡ�\n",
	"$n���������һ���������š���������$N��һ�С�\n",
	"$n�Ų�һ����һ����������$N�ı���\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취��ħ�񲽷���\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������������ħ�񲽷���\n");
	me->receive_damage("kee", 30);
	me->add("force", -2);
	return 1;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60)
		return notify_fail("�����ڽ����鸡������Ϣһ��ɡ�\n");
	if( (int)me->query("sen") < 60)
		return notify_fail("��ľ����޷������ˣ���Ϣһ���ٽ��в���ɡ�\n");
	if((int)me->query("force") < 6 )
		return notify_fail("�������������������Լ���������ȥ�ˡ�\n");
	me->receive_damage("kee", 60);
	me->add("force", -6);
	return 1;
}