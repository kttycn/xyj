// modified by Venus Oct.1997
//medical ҽ��
inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int i = (int)me->query_skill("medicine", 1);
	int j = (int)me->query_skill("literate", 1);

	if(i <= 100 && i > j+10)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о��������ҽ����\n"); 
	if(i > 100 && i <= 150 && i > j+15)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о��������ҽ����\n");
	if(i > 150 && i > j+20)
		return notify_fail("��Ķ���д�ֵȼ��������޷��о��������ҽ����\n");
	if (me->query_temp("mark/medicine")) {
		me->delete_temp("mark/medicine");
		return 1;
	}           
	return notify_fail("ҽ��ֻ��ͨ����ϰҽѧ�鼮����ߡ�\n"); 
}

int practice_skill(object me)
{       
	return notify_fail("ҽ������ͨ������ϰ������ߡ�\n");
}
