// ����������
// ר���鶾����ô�ã�ʲôʱ�����Ҳ��⣬�Ǻ�
// xintai 2/3/2001

#include <ansi.h>

int cast(object me, object target)
{
	if ( !target
	|| !userp(target)
	|| target->is_corpse()
	|| target==me)
		return notify_fail("������˭����鶾��\n");
	if (!target->query_condition("xiangsi"))
		return notify_fail("�Ǹ��˸���û���鶾����ʲô��Ц����\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��ⶾ��\n");

	if( (int)me->query("mana")  <  1200 )
		return notify_fail("��ķ���������\n");

	if ( (int)me->query_skill("pansi-dafa") < 120)
		return notify_fail("�����˿�󷨵ȼ���������Ҫ��ǿ����\n");

	message_vision(
		HIB "$N��������$nĬĬ�����뻳�У�$n����$N���˰����ů������������ƽ��������\n\n"NOR,
		me, target );
	if (random(me->query_skill("pansi-dafa", 1)-60)>10){
		target->apply_condition("xiangsi",0);
		message_vision(
		HIY "$N���������͵ĸ�����$n���мȸм����ְ�ο����������ĸ���������������˯�硣\n"NOR,
		me, target );
		target->set_temp("force_sleep",1);
		target->command_function("sleep");

		target->delete_temp("force_sleep");	}
	else {
		message_vision(
		HIY "$NͻȻ��ɫ�԰ף��ƺ�����������������Ż��һ��Ѫ������\n"NOR,
		 me, target );
	}	
                
	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("mana", -300);
	me->set("mana_factor", 0);

	return 1;
}
