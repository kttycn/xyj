// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("ս�����˹����ˣ�������\n");

	if (me->is_busy())
		return notify_fail("����æ�������£���ô���ˣ�\n");

	if ((int)me->query_skill("wuzu-xinfa", 1) < 30)
		return notify_fail("��������ķ���Ϊ��������\n");
	if( (int)me->query("force") < 50 ) 
		return notify_fail("�������������\n");
	if ((int)me->query("kee") > ((int)me->query("max_kee")-1))
		return notify_fail("�㲻��Ҫ���ˡ�\n");

	if( (int)me->query("kee") < (int)me->query("max_kee") / 4 )
		return notify_fail("��ľ������𣬸����޷�����������������\n");

	write( HIM "����ϥ������Ĭ�������ķ�����һ�ɵ���֮������������ʼ���ˡ�\n" NOR);
	message("vision",
		HIR + me->name() + "��ϥ������Ĭ���񹦣�ͻȻ���ۡ���һ�����һ���Ѫ����ɫ�������ƺ�������ࡣ\n" NOR,
		environment(me), me);

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
	me->add("force", -50);
	me->set("force_factor", 0);

	return 1;
}

