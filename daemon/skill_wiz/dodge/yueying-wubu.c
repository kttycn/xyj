//����Ӱ�貽�� yueying-wubu.c


inherit SKILL;

string *dodge_msg = ({
     "$nһ�С��辡�һ��ȵ׷硹��$Nֻ����ǰһ����������$n����Ӱ��\n",
     "$nһ�С�ɨ�����Ʒ粻����������΢�Σ��о����յرܿ���$N��һ�С�\n",
     "ֻ��$n�������һ����һ�С�����º�Ӱ�����󵴶�������һ�ԡ�\n",
     "$n����$nһ������ˮ�仨��ȥҲ�������䷭�ɣ����$N��һ�С�\n",
     "$nϢ���������������һ�С���������Ӱ�ڲ���������ƮȻ����\n",
     "$nֻ��$nһ�С����ִ���ˮ�޺ۡ����������Σ����������ת���˳����ɿ��⡣\n",
});

int valid_enable(string usage) { return (usage=="dodge"); }

int valid_learn(object me)
{
//	if( (string)me->query("gender") != "Ů��" )
//		return notify_fail("��Ӱ�貽ֻ��Ů�Բ�������\n");
	if( (int)me->query("spi") < 10 )
		return notify_fail("������Բ�����û�а취����Ӱ�貽��\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ���̫���ˣ���������Ӱ�貽��\n");
	me->receive_damage("sen", 30);
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
