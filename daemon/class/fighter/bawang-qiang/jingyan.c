// counterattack.c
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,skill;
	object weapon;
	skill = me->query_skill("bawang-qiang",1);
	if( (string)me->query("class") !="fighter")
		return notify_fail("��֪����ô����,�������������ǹ��!!\n");
	
	if( !target ) target = offensive_target(me);
       
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail(HIC"�۾���һǹ��"NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
	if(me->query("family/family_name") != "������" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���ã۾���һǹ�ݣ�\n");
	if (skill <100 ) 
		return notify_fail(" ��İ���ǹ�ĵȼ���������ʩչ���۾���һǹ�� ��\n");
	if (me->query("force")<800 )
		return notify_fail(" �����������,���ʩչ���о�ѧ? \n");
	weapon = me->query_temp("weapon");
	msg = "$Nһ�����,ʹ���˰���ǹ�ľ���"+ HIC"����һǹ"NOR+"��\n\n";
	message_vision(msg, me, target);
	msg =HIG  "$N����һ��,"+ weapon->name() +HIG"�ó�����ǹӰ,���ź�Х֮��,���ɨ��Ҷ��Ĺ���$n��"NOR+"\n";
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
		msg +=HIR "���$p��$P���˸����ֲ�����\n" NOR;
		target->start_busy(1+random(2));
	} else {
		msg += "����$p��������˿����Ϊ������\n\n" NOR;
	}
	me->add("force",-250);
	message_vision(msg, me, target);

	me->delete("env/brief_message");
	me->set_temp("BWQ_perform",8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 
	me->delete_temp("BWQ_perform");
//  weapon->move(environment(target));
	me->start_busy(1+random(1));
	return 1;
}
