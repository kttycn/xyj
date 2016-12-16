#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp, yourexp;
	object weapon;    
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ��.\n");
	if(me->query("family/family_name")!="��ѩɽ"
	&& !me->query("guild") )
		return notify_fail("������������ֻ�д�ѩɽ���˲ſ����ã�\n");

	weapon = me->query_temp("weapon");
	if (!weapon||weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽�������ʹ�ð���������\n");
	if( (int)me->query_skill("bainiao-jian",1) < 80)
		return notify_fail("��İ��񽣷��ȼ�������!\n");
	if( (int)me->query_skill("ningxue-force",1) < 80)
		return notify_fail("��ı�����Ѫ������������.\n");
	if( (int)me->query("max_force") < 800)
		return notify_fail("�������̫����!\n");
	if( (int)me->query("force") < 400)
		return notify_fail("�������������.\n");;
	myexp = (int)me->query("combat_exp")/1000*(int)me->query_skill("sword");
	yourexp = (int)target->query("combat_exp")/1000*(int)target->query_skill("dodge");
	msg = HIC"$N����һ��,��Ȼ����һ���ö�������,ϸ��������,ƽ������,���µ���.\n"
"����������մ�����а֮��,�����Ϲ�����---��������!!\n" NOR;;
	if( random(myexp*3) > yourexp)
	{
		msg += HIG"$n����������,�����Եĵ��˸���һ��.\n" NOR;
		target->start_busy(3);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
		msg += HBYEL"$Nȴ��������,�����һ����ĽǶȴ���,������,��,��,��֮����.�������⾳������Ȥ!\n" NOR;
		me->start_busy(1);
		me->add("force",-200);
	}
	else
	{
		msg += HIY"$n�ƺ����������������Ȥ������ر���һ�ԡ�\n" NOR;
		me->start_busy(3);
		me->add("force",-150);  
	}
	message_vision(msg, me, target);
	return 1;
}
