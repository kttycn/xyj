//Cracked by Roath
#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) 
		return notify_fail("��ֻ���������ķ������Լ���\n");

	if(me->query("family/family_name") != "����ɽ���Ƕ�"
	&& !me->query("guild") )
		return notify_fail("[������]�Ƿ���ɽ���Ƕ�����֮�ܣ�\n");		

	if( (int)me->query("force") < 250 )     
		return notify_fail("�������������\n");
	if( (int)me->query_temp("powerup") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	skill = me->query_skill("wuxiangforce",1);

	me->add("force", -250);
	me->receive_damage("kee", 10);
	message_vision(HIR"$N˫Ŀһ�������������ķ����������¶�ʱ��һƬ�����ס�������������ף�վ�����￴�����������ݡ�\n" NOR, me);
	me->add_temp("apply/armor", skill/2);
	me->set_temp("powerup", 1);
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill/2);

	if( me->is_fighting() ) me->start_busy(1);
	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/armor", - amount/2);
	me->delete_temp("powerup");
	tell_object(me, "��������ķ�����һ������ϣ���⽥����ȥ�ˡ�\n");
}
