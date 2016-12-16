#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int j;
	string msg;
	int ap;
	if( !target ) target = offensive_target(me);
	j = (int)me->query_skill("yinsuo-jinling",1);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С����������֡�??\n");

	if(me->query("family/family_name")!="��˿��"
	&& !me->query("guild") )
		return notify_fail("�����������֡�ֻ����˿�����˲ſ����ã�\n");
	if(!me->is_fighting(target) )
		return notify_fail("�����������֡�ֻ����ս����ʹ��!!\n");

	if((int)me->query("max_force") <1000 )
		return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") <50 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("yinsuo-jinling",1) <120)
		return notify_fail("����������弶�𻹲���ʩչ��һ�С����������֡�!!\n");
	if((int)me->query_skill("yueying-wubu",1) <100)
		return notify_fail("�����Ӱ�貽�ȼ�����!!\n");
	if((int)me->query_skill("jiuyin-xinjing",1)<100)
		return notify_fail("��ľ����ľ��ȼ�̫��!!\n");
	if((int)me->query_skill("pansi-dafa",1) <120)
		return notify_fail("�����˿�󷨵ȼ�����!!\n");
	if( (string)me->query("gender") !="Ů��")
		return notify_fail("���Ϊ����֮��,����֪��Ů���ҵ���˼??\n");
	if(me->query("family/family_name") != "��˿��" )
		return notify_fail("�㲻����˿������,���򲻵������������֡��ľ���!!\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	ap = 2 + random(1);
	msg = HIC"\n��������Ϊ����?ֱ������������!$N����һ�����,�޷���Ȼ����鶯�쳣!\n" NOR;
	message_vision(msg, me, target);

	if( (int)me->query_skill("yinsuo-jinling",1) > 180)
	{
		me->set_temp("YSJL_perform", 2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->set_temp("YSJL_perform", 5);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
		me->set_temp("YSJL_perform", 5);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		me->start_busy(ap);
	} else {
		if( (int)me->query_skill("yinsuo-jinling",1) > 150)
		{
			me->set_temp("YSJL_perform", 2);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->set_temp("YSJL_perform", 4);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->start_busy(2);
		} else {
			me->set_temp("YSJL_perform", 5);
			COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			me->start_busy(1);
		}
	}
	me->delete_temp("YSJL_perform");
	me->add("force", -100);
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	return 1;
}
