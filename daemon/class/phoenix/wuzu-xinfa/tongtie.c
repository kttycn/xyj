inherit F_CLEAN_UP;
#include <ansi.h>

void remove_effect(object me, int amount);

int exert(object me, object target)
{  
	int skill;
	object room;
	me = this_player();

	if( (string)me->query("family/family_name") != "�����" 
	&& !me->query("guild") )
		return notify_fail("�㲢�Ƿ�˳����ˣ���������ͭǽ���ڡ�\n");

	if (me->query_temp("����"))
		return notify_fail("��ո��Ѿ�ʹ�ù���ͭǽ���ڣ�\n");
	if (me->query("force")<100)
		return notify_fail("�������������\n");
	if (me->query_skill("wuzu-xinfa", 1)<40)
		return notify_fail("��������ķ��ļ��𲻹���\n");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ����𲻹���\n");
	message_vision("$N���������дʣ���ʱһ�����������$N���þò�ɢ��\n",room);
	message_vision("������Լ��ķ����������ˣ�\n",me);
	me->start_busy(3);
	me->set_temp("����",1);
	me->add_temp("apply/armor", me->query("wuzu-xinfa")/3+me->query("spells")/5+random(50));
	me->add_temp("apply/dodge", me->query("wuzu-xinfa")/3+me->query("spells")/5+random(50));
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);
	return 1;
}
void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", - amount);
	me->add_temp("apply/dodge", - amount);
	me->delete_temp("����");
	tell_object(me, "���ͭǽ����������ϣ�����Ϣ�ջص��\n");
} 
