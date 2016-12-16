// xiaoyaoyou.c
//����ң�Ρ�weiqi... 97.09.13

inherit SKILL;

string *dodge_msg = ({
	"$n�������ˣ�����ֻ������һת������һ�������$N����ӹ���\n",
	"����$N��ǰһ������Ȼ��$n��Ӱ�Ӷ��Ҳ����ˡ�\n��Ȼ��ͷ������һ��ĸ���µ����Ц����\nԭ��$n����һͷ����������ɿ��⻬���ȥ��\n",
	"$n�ҽ�̤�˸��鲽��˫��һ�񣬶�ʱ�˷���𣬾�Ȼ��$Nͷ��Խ�˹�ȥ��\n",
	"$n����һ�㣬���η�ҡֱ�ϣ�ȴ�ڰ����һ��ת�ۣ���ƮƮ��������$N���\n",
	"����$n���Ų�æ��������������ˮ������һƮ...��һƮ����ܵ�����߿��⡣\n",
	"����$n����΢�ʣ�˳��һ�ư�����������֮����\n����մ��$N�����ϵ�һ�������������Եõؽ��仯�⡣\n",
	"$nͻȻ���һ��������������$Nһ��֮�䣬Ц�úϲ�£������˿�����\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취ѧ��ң�Ρ�\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("������̫����������ң�ε���ˤ����\n");
	if((int)me->query("force") < 3 )
		return notify_fail("�������������������ܳ˷����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
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
