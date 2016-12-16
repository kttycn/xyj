// jushu.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail(HIR "��Ҫ�����ҧ˭��\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail(HIR "��ķ����������޷�����Ϊ����\n");

	if((int)me->query("sen") < 20 )
		return notify_fail(HIR "���޷����о��������Լ�ҧ����\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write(HIC "Oh��Mygod�������ȥ͵����ȥ�ˣ�\n");
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
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIM "$N�ٺٵļ�Ц��������������գ����һֻ��������Ľ�Ƥ�����ſ�Ѫ���ڣ�
������һ����$n�ſ�ҧȥ��\n" NOR,
			//initial message
		HIY "���ҧ�����ţ����û��$nҧ����\n" NOR, 
			//success message
		HIR "����$n��ǧ��һ��֮�ʶ��˿�����\n" NOR, 
			//fail message
		HIW "���ǽ�Ƥ����$n�Է���һ��������ҧ����$N�����ţ�\n" NOR, 
			//backfire initial message
		HIW "���ҧ�����ţ����û��$nҧ����\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(0));
	return 1+random(2);
}

