#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/2 )
		return notify_fail("������ͷ�Բ����ѣ�ûͷ��Ӭ�ƵĿ��Ӳ�����\n");

	if( (string)me->query("family/family_name") != "��ʥ��" 
	&& !me->query("guild") )
		return notify_fail("�㲢����ʥ�ŵ��ӣ������۲��������㡣\n");

	message_vision(HIC "$N�૵����˼������ͻȻ�����У������۾��ң�\n" NOR, me);
	message_vision(HIC "ֻ�������۴��ƶ�������\n\n" NOR, me);

	if(me->is_fighting() ) {
		if(random((int)me->query("max_mana")) > (int)target->query("max_mana")/2 && random((int)me->query("mana")) > (int)target->query("mana")/2 ) {
			message_vision(HIC "����������һ��ץס$N��������ͷ����ʱ������������Ӱ�����ˣ�\n" NOR, me);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
			if(random(3)==0) me->move("/d/wusheng/room1");
			else if(random(3)==1) me->move("/d/wusheng/room2");
			else me->move("/d/wusheng/room3");
			message_vision(HIC "ֻ��ſ����һ����$N�Ӱ���е����������˸�ƨ�ɿ�����\n" NOR, me);
		}
		else{
			message_vision(HIC "����������һ�ˣ�ȴ��$n������ס���岻��ս�š�ֻ�ö���$N���һ�������˻�ȥ��\n" NOR, me, target);
			me->receive_damage("sen", 50);
			me->add("mana", -100);
		}
	}

	else{
		message_vision(HIC "ֻ��ſ����һ����������������һ���ƴ���$N�����ϣ�$N�����˸��߻���أ�\n" NOR, me);
		me->add("mana", -100);
	}

	return 3+random(5);
}

