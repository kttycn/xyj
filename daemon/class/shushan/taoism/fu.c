// fu by yushu 2000.11
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 110;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩ��ʦ������\n");

	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
		return notify_fail("�㲻����ɽ���ɵ��ӣ������á���ʦ��������\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("��һ�ż���Ȼ�������\n");
		return 1;
	}
	

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj,    
			//success adjustment
		damage_adj,     
			//damage adjustment
		"kee",	   
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIC "\n$Nһ����ɱ֮����̧���Գ�һ����ʦ����������һ�·ɵ���գ�����$n��\n" NOR,
			//initial message
		HIR "\n$n����Ӱ��ס���������һ����Ѫ��\n" NOR, 
			//success message
		YEL "���$n���һ�����˹�ȥ��\n" NOR, 
			//fail message
		HIC "����$n��ָһ�������һ������ʦ������$N��ȥ��\n" NOR, 
			//backfire initial message
		HIR "����ˣ���һ����ʦ����$nƾ�ջ�ȥ��\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}
