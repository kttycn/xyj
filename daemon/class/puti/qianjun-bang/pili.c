
//vikee 
//pili.c you can add it to the directory /daemon/class/puti/qianjun-bang/
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void pili_ok(object);
int perform(object me, object target)
{
	object weapon;
		
	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С��������򡹣�\n");

	if(me->query("family/family_name") != "����ɽ���Ƕ�" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á���������?\n");
	if(!me->is_fighting())
		return notify_fail("����������ֻ����ս����ʹ�ã�\n");

	if((int)me->query("max_force") < 500 )
		return notify_fail("�������������\n");

	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

	if((int)me->query("sen") < 500 )
		return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	if((int)me->query_skill("qianjun-bang", 1) < 100)
		return notify_fail("���ǧ�������𻹲�����ʹ����һ�л������ѣ�\n");

	if(me->query_temp("no_pili"))
		return notify_fail("������ʹ�Ͳ����ˣ�\n");
	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(HIC"\n$N���㾫������һת��������������$n���������У�\n"NOR,me,target);

	me->set_temp("QJB_perform", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->set_temp("QJB_perform", 1);  
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	me->set_temp("QJB_perform", 6);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete_temp("QJB_perform");

	me->receive_damage("sen", 100);
	me->add("force", -100);
	me->set_temp("no_pili",1);
		call_out("pili_ok",2+random(2),me);


	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}

	return 1;
}

void pili_ok(object me)
{
	if (!me) return;
	me->delete_temp("no_pili");
}	 
