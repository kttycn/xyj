//Cracked by Roath

inherit SKILL;
string type() { return "spells"; }
int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( me->query("family/family_name") != "��ɽ����" )
        return notify_fail("��ʦ�ɷ�ֻ����ɽ���˲ſ���ѧ��\n");

        if( (int)me->query_skill("spells",1) < 20 )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ��ʦ�ɷ���\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("shushan") + "/taoism/" + spell;
}
string query_shuxing()
{
	return "jin";
}

int apperception_skill(object me)
{
	if( (int)me->query("sen") < 60
	|| (int)me->query("mana") < 10 )
		return notify_fail("��ķ��������㣬û�а취����������ʦ�ɷ���\n");
	me->receive_damage("sen", 60);
	me->add("mana", -10);
	write("�㰴����ѧ������ʦ�ɷ���\n");
	return 1;
}
