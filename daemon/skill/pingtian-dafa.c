// dao
inherit SKILL;


int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells", 1) < 20 )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰƽ��󷨡�\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("yaomo") + "/kusong/pingtian-dafa/" + spell;
}

string query_shuxing()
{
	return "huo";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("��ķ��������㣬û�а취��������ƽ��󷨡�\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("�㰴����ѧ����ƽ��󷨡�\n");
	return 1;
}
