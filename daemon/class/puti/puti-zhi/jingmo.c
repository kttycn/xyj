// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl;
	if(me->query("family/family_name") != "����ɽ���Ƕ�" 
	&& !me->query("guild") )
		return notify_fail("�㲻�ǵ��ҵ���,����ʲô!!\n");   
	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("[��ħһָ]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʩ�þ�ħһָ!!\n");
	if(target->is_busy())
		return notify_fail(target->query("name")+"�Ѿ����������ˣ�\n");
	if( (int)me->query_skill("puti-zhi",1) < 100)
		return notify_fail("�������ָ����������!!\n");
	if( (int)me->query("max_force") <1000)
		return notify_fail("�������������ǿ,����ʩչ��ħһָ!!!\n");
	if( (int)me->query("force") <300)
		return notify_fail("��������������,�޷�ʹ����ħһָ!!\n");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int)me->query_skill("puti-zhi",1)/30;
    msg = HIC"\n$N��ɫ��ת����,������ָ�������,���Ǿ����,������ľ�ħһָ!!\n" NOR;
	if(random(myexp)>yourexp/2)
	{
		message_vision(msg + "\n", me, target);
		msg = HIG "$nֻ��һ�ɾ���ֱ͸�羮Ѩ,��ʱȫ��һ��,��������!!\n" NOR;
		message_vision(msg, me, target);
		target->start_busy(1+random(lvl));
	}
	else {
		message_vision(msg +"\n", me, target);
		msg = HIY "����$n�ƺ�������$N����ͼ,���ն������һ��!!\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
	}
	me->add("force",-150);
//if( living(target) )target->kill_ob(me);
	return 1;
}
