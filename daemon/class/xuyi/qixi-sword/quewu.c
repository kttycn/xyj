#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon, ob;
	if(me->query("family/family_name") != "����ɽ" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á���Ϧȵ�衹?\n");

	if((int)me->query("max_force") < 300 )
		return notify_fail("�������������\n");

	if((int)me->query("force") < 300 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 300 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	extra = me->query_skill("qixi-sword",1);
	if ( extra < 50) return notify_fail("�����Ϧ�������������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| !me->is_fighting(target) )
		return notify_fail("����Ϧȵ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!(ob = me->query_temp("weapon"))
	|| (string)ob->query("skill_type") != "sword" )
		return notify_fail("û�н���ô��ʩչ����Ϧȵ��ݣ�\n"); 
	if((int)me->query("bellicosity") > 150)
		return notify_fail("���ɱ��̫�أ�ʩչ�������������ʽ��\n");
	weapon = me->query_temp("weapon");
	message_vision(HIY  "$Nʹ����Ϧ�����еģ���Ϧȵ��ݣ�����ƮƼ����裬���������Ƴ��ա�һ���������������е�"+ weapon->name()+ HIY"�������$n����\n��һ����\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(HIY"�ڶ�����\n" NOR,me);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(HIY"��������\n" NOR,me);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->receive_damage("sen", 100);
	me->add("force", -100);
	me->start_busy(3);
	return 1;
}


