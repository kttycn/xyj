// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "beauty"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "�绨����" NOR,
		BLU "������֬" NOR,
		HIB "��Բ����" NOR,
		HIB "��������" NOR,
		YEL "������" NOR,
		YEL "�������" NOR,
		CYN "���ʻ���" NOR,
		HIW "�ഺ��פ" NOR
		//�������
		//������
	});

	grade = level / 20;	
	
	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
