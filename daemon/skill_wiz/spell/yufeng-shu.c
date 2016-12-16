//yufeng-shu  ����������

inherit SKILL;

int valid_enable(string usage)
{
	return usage == "spells";
}

int valid_learn(object me)
{
	if( (int)me->query_skill("spells", 1) < 10
	|| (int)me->query_skill("spells", 1) <=
	(int)me->query_skill("yufeng-shu", 1) )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��������\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("������ֻ����ѧ��������\n");
}

string cast_spell_file(string spell)
{
        return CLASS_D("phoenix") + "/yufeng-shu/" + spell;
}

string type() { return "magic"; }

string query_shuxing()
{
	return "huo";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 100
	|| (int)me->query("mana") < 18 )
		return notify_fail("��ķ��������㣬û�а취����������������\n");
	if( (int)me->query("kee") < 60
	|| (int)me->query("force") < 10 )
		return notify_fail("��������������㣬û�а취����������������\n");
	me->receive_damage("sen", 100);
	me->receive_damage("kee", 60);
	me->add("mana", -18);
	me->add("force", -10);
	write("�㰴����ѧ������������\n");
	return 1;
}
