inherit SKILL;

#include <ansi.h>

int valid_enable(string usage) { return usage=="force"; }

string level_description(int level)
{
	if ( level < 10 )
		return BLU "������ʼ" NOR;
	else if ( level < 20 )
		return HIB "�����;" NOR;
	else if ( level < 30 )
		return YEL "�ռ�����" NOR;
	else if ( level < 40 )
		return CYN "��ͷ����" NOR;
	else if ( level< 50 )
		return HIW "����ľ��" NOR;
	else 
		return HIR "�޿ɾ�ҩ" NOR;
}

int practice_skill(object me)
{
        return notify_fail("�����ķ�ֻ����ʦ��ѧ�����Ǵӷ��������������ȡ�\n");
}
string exert_function_file(string func)
{
        return CLASS_D("force") + "/idle-force/" + func;
}
