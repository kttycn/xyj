// xiantian-force ������Ǭ������

/*
����Ǭ����
��������֮����������һ��Ϊ���ã��������ھ��ص�ʱ�򣬿������������
����ʹ��һ�С���ת��ء������Ǭ������ת���ڳ���������һ���⡣
*/

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("����Ǭ����ֻ����ʦ��ѧ�����Ǵ�����(exert)�����������ȡ�\n");
}
string exert_function_file(string func)
{
	return CLASS_D("wusheng") + "/xiantian-force/" + func;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else if ( level < 290 ) return 8;
	else return 9;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return BLU "��"+chinese_number( stage(level) )+"�ء�" NOR;
	else if ( stage(level) < 5 )
		return HIB "��"+chinese_number( stage(level) )+"�ء�" NOR;
	else if ( stage(level) < 7 )
		return YEL "��"+chinese_number( stage(level) )+"�ء�" NOR;
	else if ( stage(level) < 9 )
		return CYN "��"+chinese_number( stage(level) )+"�ء�" NOR;
	else 
		return HIW "��"+chinese_number( stage(level) )+"�ء�" NOR;
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 60
	|| (int)me->query("sen") < 60 
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������Ǭ������\n");
	me->receive_damage("kee", 60);
	me->add("force", -10);
	write("�㰴����ѧ��������Ǭ������\n");
	return 1;
}
