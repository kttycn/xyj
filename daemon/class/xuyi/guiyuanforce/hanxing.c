#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
	string msg;
	int lvl, ap, dp;

	if( !target ) target = offensive_target(me);
	if((int)me->query_skill("force") < 80 )
		return notify_fail("����ڹ���Ϊ�����ߣ�\n");

	if( !target
	|| !target->is_character()
	|| target->is_corpse() )
		return notify_fail("��Ҫ��˭ʩչ������Ǿ���\n");

	if(target->query_temp("in_hanxing"))
		return notify_fail("�����ڲ�����Ҫʩչ���Ǿ���\n");

	if((int)me->query("force") < 300 )
		return notify_fail("�������������\n");

	if((int)me->query("kee") < 50 )
		return notify_fail("��û�а취���о���\n");

	me->add("force", -300);
	me->receive_damage("kee", 50);

	if( random(me->query("max_force")) < 30 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}

	msg = HIC "$N���������дʣ�һ����â��$Nͷ�������������$n��Χ��\n\n" ;

	ap = me->query_skill("force");
	ap = ( ap * ap /100 * ap/30 ) * (int)me->query("kee") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
	msg +="��â����һ����ף�����ס$n��ȫ��\n";
	lvl = (int)me->query_skill("force")/4;
		target->set_temp("in_hanxing",1);
		target->add_temp("apply/armor",lvl);
		seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_hanxing",target, lvl :),
		random(lvl*3)+lvl);
	} else
		msg += "�������Ͼ���ʧ�ˡ�\n";
	if(me == target) 
	{
		msg = replace_string(msg, "$n","$N");
		message_vision(msg+NOR,me);
	}
	else
		message_vision(msg+NOR, me, target);
	me->start_busy(1);
	return 1;
}

void remove_hanxing(object me, int lvl)
{
	me->delete_temp("in_hanxing");
	me->add_temp("apply/armor",-lvl);
	message_vision(HIY "\n\n$N����Ĺ�׷���ҫ�۵�һ������ʧ�ˡ�\n\n" NOR, me);
}

