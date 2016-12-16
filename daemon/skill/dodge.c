// dodge.c
#include <ansi.h>

inherit SKILL;

string *dodge_msg = ({
	"���Ǻ�$p$lƫ�˼��硣\n",
	"���Ǳ�$p����ض㿪�ˡ�\n",
	"����$n����һ�࣬���˿�ȥ��\n",
	"���Ǳ�$p��ʱ�ܿ���\n",
	"����$n����׼�������Ų�æ�ض㿪��\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "���ֱ���" NOR,     
		BLU "������ӯ" NOR,
		HIB "�����鶯" NOR,     
		HIB "��������" NOR,
		HIB "�����ɺ�" NOR,
		CYN "̤ѩ�޺�" NOR,
		CYN "��Ƽ��ˮ" NOR,
		CYN "��ȥ���" NOR,     
		HIC "һкǧ��" NOR,
		HIC "���λ�Ӱ" NOR,
		HIW "��ն���" NOR,
		HIW "�������" NOR     
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취��������Ṧ��\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("�㰴����ѧ��������Ṧ��\n");
	return 1;
}
