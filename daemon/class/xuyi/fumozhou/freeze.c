#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	string msg;
	int success, ap, dp, howlong;
	int dayphase;

	dayphase =NATURE_D->query_current_day_phase();

//        if(!me->is_fighting())
//        return notify_fail("������ֻ������ս����ʩչ��\n");
	if( !target ) target = offensive_target(me);
	if((int)me->query_skill("spells", 1) < 100 || (int)me->query_skill("fumozhou",1) < 60)
		return notify_fail("�㻹ûѧ�Ắ��������\n");

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ���������\n");

	if( !living(target) )
		return notify_fail("�˶������㻹Ҫ���˼ң�\n");
	if(target->query_temp("no_move") )
		return notify_fail("�б�Ҫ��"+target->query("name")+"�Ѿ����ܶ��ˡ�\n");

	if((int)me->query("mana") < 400 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("��ľ���û�а취��Ч���У�\n");

	me->add("mana", -400);
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 30 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}

	msg = HIW "$N˫��һ�ۣ��γ�һ������ĺ�������$n������\n\n" ;

	success = 1;
	ap = me->query_skill("fumozhou", 1);
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("combat_exp");
	dp = target->query("combat_exp");
	if (dayphase < 6){
		if( random(ap + dp) < dp ) success = 0;
	} 
	else if( random(ap + dp) < dp / 2) success = 0;

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
	if (dayphase < 6){
		if( random(ap + dp) < dp*2/3 ) success = 0;
	} 
	else if( random(ap + dp) < dp / 2) success = 0;

	ap = (int)me->query("mana");
	dp = (int)target->query("mana");
	if (dayphase < 6){
		if( random(ap + dp) < dp ) success = 0;
	}
	else if( random(ap + dp) < dp * 2 / 3) success = 0;

	howlong = 0;        
	if(success == 1 ){
		msg +=  HIW "����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n" NOR;
		target->set_temp("frozen",1);
		if( target->is_die() ) return 1;

		target->set_temp("no_move", 1); 

		howlong = (me->query_skill("spells", 1) / 10)+1;
		if(howlong>60) howlong=60;
	}
	else {
		msg +=  HIR "$n������м���ӻ��ֱ㽫������ɢ�ˣ�\n" NOR;   
	} 

	message_vision(msg+NOR, me, target);

	if( living(target) ) target->kill_ob(me);

	if (success == 0) {
		return 1+random(2);
	}

	if( howlong>0 ) call_out("remove_frozen", howlong, target);

	return 3+random(5);
}


void remove_frozen(object target)
{ 
	if( !target ) return;
	if( !living(target) ){
		call_out("remove_frozen", 1, target);
		return;
	}
	if(target) target->delete_temp("no_move");      
	message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n" NOR, target);
	if(target) target->delete_temp("frozen");
	return;
}
