// spells.c
#include <ansi.h>

inherit SKILL;


string cast_spell_file(string spell)
{
        return "/daemon/class/spells/" + spell;
}

//this does not work yet. check later...cglaem.
// Implemented by Dream on 7/22/97.

string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "���߷���" NOR,     
		HIB "�����仯" NOR,
		HIB "���Ƽ���" NOR,     
		HIB "Ԥ֪����" NOR,
		HIB "�������" NOR,     
		CYN "���绽��" NOR,
		CYN "������ɽ" NOR,     
		CYN "���ǻ���" NOR,
		HIC "��������" NOR,     
		HIC "�任Ī��" NOR,
		HIW "�����ޱ�" NOR
	});

	grade = level / 30;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

string type() { return "magic"; }

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("mana") < 10 )
		return notify_fail("��ķ������������������û�а취�������������\n");
	me->receive_damage("kee", 100);
	me->receive_damage("sen", 100);
	me->add("mana", -10);
	write("�㰴����ѧ�������������\n");
	return 1;
}
