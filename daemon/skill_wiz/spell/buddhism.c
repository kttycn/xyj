// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells") <= (int)me->query_skill("buddhism") )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��˷𷨡�\n");
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("bonze") + "/buddhism/" + spell;

	}

string type() { return "magic";}

string query_shuxing()
{
	return "tu";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("��ķ��������㣬û�а취���������˷𷨡�\n");
	if( (int)me->query("bellicosity") > 0 )
		return notify_fail("���ɱ��̫�أ��޷�������˷𷨡�\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("�㰴����ѧ�����˷𷨡�\n");
	return 1;
}
