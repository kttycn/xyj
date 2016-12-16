// perception.c
#include <ansi.h>

inherit SKILL;

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "��ͷ����" NOR,     
		HIB "��������" NOR,
		HIB "���ֿ��" NOR,     
		CYN "�������" NOR,
		HIC "�ֵ�����" NOR,     
		HIW "������͵" NOR,
	});

	grade = level / 10;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취����͵����\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("�㰴����ѧ����͵����\n");
	return 1;
}
