// throwing.c

inherit SKILL;

int apperception_skill(object me)
{
	if( (int)me->query("kee") < 100
	|| (int)me->query("sen") < 100
	|| (int)me->query("force") < 10 )
		return notify_fail("����������������������û�а취������ʹ�á�\n");
	me->receive_damage("kee", 100);
	me->add("force", -10);
	write("�㰴����ѧ������ʹ�á�\n");
	return 1;
}