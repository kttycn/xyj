// dandiao.c ��Ӱ����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>

inherit SSERVER;
void remove_effect(object me, int a_amount, int d_amount);

int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ӱ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

     if(me->query("family/family_name")!="��˿��"
	&& !me->query("guild") )
           return notify_fail("����Ӱ������ֻ����˿�����˲ſ����ã�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("chixin-jian", 1) < 40 )
		return notify_fail("��ĳ����鳤����������죬����ʹ�á���Ӱ��������\n");
	
	if( (int)me->query_skill("jiuyin-xinjing", 1) < 40 )
		return notify_fail("��ľ����ľ�������죬����ʹ�á���Ӱ��������\n");
	
	if( (int)me->query("force") < 300  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_temp("dandiao_wu") ) 
		return notify_fail("���Ѿ����˹����ˡ�\n");

	msg = MAG"$N˫������" + weapon->name() + MAG"����â������һʽ����Ӱ��������Ԧ�����Ҿ��׵���$n��̣�\n"NOR;
	message_vision(msg, me, target);

	skill = (int)me->query_skill("chixin-jian",1);
	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/dodge", -skill/4);
	me->set_temp("hsj_wu", 1);

	me->set_temp("CXJ_perform", 15);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("CXJ_perform");

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3, skill/4 :), 20);
	me->add("force", -100);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int a_amount, int d_amount)
{
	me->add_temp("apply/attack", - a_amount);
	me->add_temp("apply/dodge", d_amount);
	me->delete_temp("dandiao_wu");
	tell_object(me, "�����Ӱ����������ϡ�\n");
}
