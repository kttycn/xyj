//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;

	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      !me->is_fighting(target) )
		return notify_fail("�۽���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if(me->query("family/family_name")!="�Ϻ�����ɽ"
	&& !me->query("guild") )
		return notify_fail("���Ƿ��ŵ��Ӳ����á�������������\n");
// ����ɱ���ߣ����󲻷�����ʵ�������趨��ɱ������
	if( (int)me->query("bellicosity") > 400 )
		return notify_fail("���ɱ��̫�أ��޷�ʩչ���ž�����\n");

	extra = me->query_skill("lunhui-zhang",1)/10+me->query_skill("staff",1)/10;
		if ( extra < 20) return notify_fail("����ֻ��ȷ�������ȷ����������죬�����޷����ã�\n");

	if(me->query_skill("lotusforce",1) < 100)
		return notify_fail("����ڹ����Ӳ��㣬�޷�������磬ʩչ��������������\n");

	if((string)me->query_skill_mapped("force")!="lotusforce")
		return notify_fail("����������������̨�ķ�Ϊ���ӡ�\n");

	if(me->query("max_force") < 500)
		return notify_fail("����������㣬��������Ӷ�һ�����ȡ�\n");

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
	me->start_busy(3+random(2));
	return 1;
}
