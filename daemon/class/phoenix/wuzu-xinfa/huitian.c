#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����й���������\n");

	if ((int)me->query_skill("wuzu-xinfa", 1) < 40)
		return notify_fail("��������ķ���Ϊ��������\n");
	if( (int)me->query("force") < 50 )
		return notify_fail("�������������\n");

	if( (int)me->query("eff_jing") < (int)me->query("max_jing") / 3 )
		return notify_fail("���Ѿ��ǳ�ƣ���ˣ�ֻ��һ��������������Σ�գ�\n");

	write( HIW "��ȫ����ɣ���������ʼ�й���\n" NOR);
	message("vision",
		HIW + me->name() + "�й�һ���죬��������һ������վ����������ɫ�������ö��ˡ�\n" NOR,
		environment(me), me);

	me->receive_curing("sen", 10 + (int)me->query_skill("force")/5 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}

