// lotusforce.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1;}


int practice_skill(object me)
{
	return notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string exert_function_file(string func)
{
	return CLASS_D("bonze") + "/lotusforce/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취���������ķ���\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ���������ķ���\n");
	return 1;
}
