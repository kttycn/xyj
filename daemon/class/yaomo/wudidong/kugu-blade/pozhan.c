//yushu-2000.10
//pozhan.c 	
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int delay, myblade;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ս���У�¶ʲô������\n");
	if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�"
	&& !me->query("guild") )
	    return notify_fail("�㲻��������壬¶����������Ҳ�����ϵ���\n");

	myblade=(int)me->query_skill("kugu-blade",1);
	if(myblade>160) myblade=160; // mon 12/7/98
	if(myblade<50) 
		return notify_fail("�����Ϊ�����¶��������̫Σ���ˡ�\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = CYN "$N����ʽͻȻһ�䣬���ȫ���·����������������ٳ���\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")) {
		msg += "$n�빥��ȴ��֪���ĸ��������棬�ĸ��Ǽ١�\n";
		msg += "���$p��$P���˸����ֲ�����\n" NOR;
		delay=(int)me->query_skill("kugu-blade", 1) /5;
		if ( delay > 10 ) delay = 10;
		if ( delay < 5  ) delay = 5; //modified by vikee 2000. 10

		target->start_busy(delay);
		me->start_busy(random(2));
	} else {
		msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
		
		me->start_busy(2);
		//here is modified by vikee
	}
	message_vision(msg, me, target);

	return 1;
}
