//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,j,k,lmt;
	object weapon;
	if( me->query("family/family_name") != "��ׯ��" 
	&& !me->query("guild") )
		return notify_fail("�����ׯ�۵��ӣ�����ʹ�á�Ⱥħ���衽��\n");
	j=(int)me->query_skill("fumo-zhang",1)+me->query_skill("staff",1)/2;
	k=(int)me->query_skill("fumo-zhang",1);
	if(j<180 || k<1)            
		return notify_fail("��ķ�ħ�ȷ�������ȷ����������죬�����޷����á�Ⱥħ���衹��\n");
	if(me->query_skill("zhenyuan-force",1) < 120)
		return notify_fail("����ڹ����Ӳ��㣬�޷�������磬ʩչ������Ⱥħ���衹��\n");

	if((string)me->query_skill_mapped("force")!="zhenyuan-force")
		return notify_fail("��Ⱥħ���衹��������Ԫ��Ϊ���ӡ�\n");

	if(me->query("max_force") < 500)
		return notify_fail("����������㣬��������Ӷ�һ�����ȡ�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("��Ⱥħ���衹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(me->query("family/family_name") != "��ׯ��")
		return notify_fail("��Ⱥħ���衹ֻ����ׯ�۵��ӲŶ������ʹ�ã�\n");

	weapon = me->query_temp("weapon");

	msg = HIY  "$N����������������֮���һ����磬����"+ weapon->name()+  "Ҳ�����籩������$n������" NOR;

	message_vision(msg,me,target);

	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra);
	lmt = 9;
	for(i=6;i<=lmt;i++)
	{
		me->set_temp("FMZ_perform",i);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
	me->add("force",-extra*5);
	me->delete_temp("FMZ_perform");
	me->start_busy(2+random(1));
	return 1;
}
