inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("��Ȫ��ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("fighter") + "/lengquan-force/" + func;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취������Ȫ�񹦡�\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ������Ȫ�񹦡�\n");
	return 1;
}
