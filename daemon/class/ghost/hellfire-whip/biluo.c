// �����Ȫ
// yangwl 1/31/2001
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ��"+HIG"�������Ȫ��"+NOR"��\n");

	if((int)me->query("force") < 150+(int)me->query("force_factor") )
		return notify_fail("�������������\n");
// if (me->query_temp("hell_pfm_busy")) return notify_fail("����ù������Ȫ��\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("hellfire-whip", 1) <120)
		return notify_fail("����һ�޼��𻹲�����\n");
	
	if(me->query("family/family_name") != "���޵ظ�"
	&& !me->query("guild") )
		return notify_fail(HIG"�������Ȫ��"+NOR"��ڤ�粻��֮�ܣ�\n");

	me->add("force", -25-(int)me->query("force_factor"));
	me->receive_damage("kee", 100);

	if( random(me->query("max_force")) < 50 ) {
		write("��⣬û�ɹ���\n");
		return 1;
	}


	COMBAT_D->attacking_perform(
		me, 
			//attacker 
		target, 
			//target
		(int)me->query_skill("hellfire-whip", 1), 
			//level of skill used
		150, 
			//success adjustment
		100, 
			//damage adjustment
		"qi", 
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		MAG "$N�Һ�һ����һ����Ѫ�����գ�����������Ѫһ�ƣ����г���Х��������
����������������Ϯ$n���ؿ��ߴ���Ѩ��\n" NOR,
			//initial message
		MAG "���������$n�ؿ���������������һ����Ѫ��\n" NOR, 
			//success message
		MAG "����$nһ����Ц������ҡ�Σ����˿�ȥ��\n" NOR, 
			//fail message
		MAG "���Ǳ�$n������һ�ƣ����޵�תͷ��������������\n" NOR, 
			//backfire initial message
		MAG "���ֻ�������͡�һ����$n��������͸�ض�����\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(random(2));
//       me->set_temp("hell_pfm_busy",1);
// me->set_temp("no_move",1);
// call_out("remove_no_move",3,me);
//  call_out("remove_effect",5+random(3),me);
	return 1;
}
/*
void remove_effect(object me) {
if (!me) return;
  me->delete_temp("fc_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
*/
