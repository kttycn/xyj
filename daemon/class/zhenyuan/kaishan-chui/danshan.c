// happ@ys

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon, ob;
	if( !(ob = me->query_temp("weapon"))
	||      (string)ob->query("skill_type") != "hammer" )
		return notify_fail("ʹ�á����ɵ�ɽ�������ô���\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	if( me->query("family/family_name") != "��ׯ��" 
	&& !me->query("guild") )
		return notify_fail("�����ׯ�۵��ӣ�����ʹ�á����ɵ�ɽ����\n");
	if( me->query_skill("kaishan-chui",1) < 60 )
		return notify_fail("��Ŀ��촸���𲻹���\n");
	extra = me->query_skill("force")/6 ;
	if ( extra < 30) return notify_fail("�������̫����ʹ���������ɵ�ɽ����\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("�����ɵ�ɽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	me->add_temp("apply/damage", extra);
	msg = HIY  "$N˫��һ�ݣ��߾�����"+ weapon->name()+"����$n�ʹ���ȥ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),0);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
