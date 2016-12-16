// drift_sense.c
#include <ansi.h>
inherit F_CLEAN_UP;
int cast(object me)
{
	object target = find_living("ghost");
	if(!target) return notify_fail("��Ҫ�ҵĹ�û�з���?\n");
	if( me->is_fighting() )
		return notify_fail("ս�����޷�ʹ��Ѱ������\n");
	if( me->query("mana") < 30 )
		return notify_fail("��ķ���������\n");
	if( me->query("sen") <= 35 )
		return notify_fail("�������������\n");
	if( !target->is_ghost())
		return notify_fail("Ѱ����ֻ���ҹ�\n");
	if((int) me->query_skill("gouhunshu",1) < 10)
		return notify_fail("��Ĺ������������");
	me->add("mana", -30);
	me->receive_damage("sen", 30);
	message_vision( HIY "$N��ͷ��Ŀ����ʼʩչѰ���� ....\n" NOR, me);
	if( random(50) > (int)(me->query_skill("gouhunshu"))){
		write("����Ϊ����������ʧ���ˡ�\n");
		return 1;
	}
	message_vision( HIY"\nһ�ź�����Ȼ��ס$N���������ᣬ��������һ����ʧ����Ӱ���٣�\n\n" NOR,me);
	me->move(environment(target));
	message_vision(HIY"\n�����ǰͻȻ����һ�ź�����������¶��һ����Ӱ��\n\n" NOR,me);
	return 1;
}
