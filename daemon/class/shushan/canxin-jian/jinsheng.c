//jinsheng ��������

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, qi,ap, dp,qixue,eff_qi,max_qi,qi_pcg;

	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) || !living(target))
		return notify_fail(HIW"��ֻ����ս����ʹ�á�\n"NOR);
	if(me->query("family/family_name")!="��ɽ����"
	&& !me->query("guild") )
		return notify_fail("�㲻����ɽ���ӣ������á��н���������\n");
	if(me->query("shushan/jinsheng_perform")!=1)
		return notify_fail("�㻹û��ᡸ������������\n");

	if (me->query("eff_kee")<me->query("max_kee")/3
	&&me->query("kee")<300)
		return notify_fail(HIY"��δ��ɽ��ˮ���ĵز���û��Ҫƴ����\n"NOR);
	if((int)me->query("max_force") < 1500 )
		return notify_fail("����ڹ�̫�\n");
	if((int)me->query("max_mana") < 1500 )
		return notify_fail("��ķ���̫�\n");
	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");
	if((int)me->query("mana") < 500 )
		return notify_fail("��ķ������㣡\n");
	if((int)me->query_skill("taoism", 1) < 150)
		return notify_fail("�����ʦ�����ȼ�����������ʹ�á��н���������\n");
	if((int)me->query_skill("sword", 1) < 150)
		return notify_fail("��Ļ��������ȼ�����������ʹ�á��н���������\n");

	me->set("kee", 0);
	me->set("eff_kee",eff_qi*random(10)/100);
	me->set("sen",0);
	me->set("eff_sen",me->query("eff_sen")*random(10)/100);
	me->set("force",0);
	me->set("mana",0);

	message_vision(HIB"\n$N�ۼ����У������˷�����������ʫ������Ĭ�",me,target);
	message_vision(HIG"\n\n���е���һ�ж�ֻ�еȴ�������......",me,target);
	message_vision(HIB"\n\n$Nһ��ˣ�һ�С��н���������������"+weapon->name()+NOR+HIB"��Ϊһ��ֱ��$n���������� \n\n"NOR,me,target);

	ap = me->query_skill("sword", 1);
	ap = ap * ap * ap /10;
	ap = ap + (int)me->query("combat_exp");
	dp = target->query_skill("dodge",1);
	dp = dp * dp * dp /10;   
	dp = dp + target->query("combat_exp");
	dp = dp*qi_pcg/50;  
	if(random(2)+(random(ap + dp) <  dp) ) {
		message_vision(HIB"\n\n$nһ�����Ʋ��ƴ�������Խ����Ȼ���Ǳ�����֮�ʽ��ҵض������ƴ����һʽ������\n\n"NOR,me,target);
		target->start_busy(5+random(3));
	} else {
		target->die();
		message_vision(HIB"\n\n$n����$N��˾�������Ȼ����������˲��һ����������$n���ϵ��ش���������\n\n"NOR,target,me);
	}

	message_vision(HIR"\n\n����д���һ����̾������ҡ��������� \n\n"NOR,me);

	me->unconcious();
	me->start_busy(5+random(3));
	return 1;
}
