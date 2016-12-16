// jianzhang.c  

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count;

	if( !me->is_fighting() )
		return notify_fail("������������ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != ("spear"))
		return notify_fail("��������������ʼʱ��������һ��ǹ��\n");

	if(me->query("family/family_name") != "������" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�����������?\n");
	if( (int)me->query("force") < 80 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("lengquan-force",1) < 15 )
		return notify_fail("�����Ȫ�񹦲�����\n");

	if( (int)me->query_skill("spear",1) < 10 ||
	    me->query_skill_mapped("spear") != "bawang-qiang")
		return notify_fail("��İ���ǹ���������ң��޷�ʹ�÷���������\n");

	msg = HIY "$Nʹ������������������������������Ȼ�ӿ죬��˲��������У�\n" NOR;
	message_vision(msg, me);

	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("force", -100);
	me->start_busy(3);

	if(!ob->is_fighting(me)) ob->fight_ob(me);
	return 1;
}
