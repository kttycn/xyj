// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// fumozhou
inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("spells",1) < 20 )
		return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��ħ�䡣\n");
	if( (int)me->query("bellicosity") < 100 )
		return notify_fail("���ɱ��̫�ᣬ�޷����Է𷨷�ħ�ľ��衣\n");
	return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("xuyi") + "/fumozhou/" + spell;
}

string query_shuxing()
{
	return "jin";
}
int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("��ķ��������㣬û�а취���������ħ�䡣\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("�㰴����ѧ�����ħ�䡣\n");
	return 1;
}
