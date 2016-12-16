#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void sword_ok(object);
int perform(object me, object target)
{
	int ap,dp,damage;
	if( !target ) target = offensive_target(me);
	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ��һ�С���â����\n");
	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
        return notify_fail("�㲻����ɽ���ɵ��ӣ������á���â��?\n");
	if(!me->is_fighting())
		return notify_fail("����â��ֻ����ս����ʹ�ã�\n");
	if((int)me->query("max_force") < 500 )
	if(me->query("shushan/sword_perform")!=1)
		return notify_fail("�㻹û��ᡸ��â����\n");

		return notify_fail("����������㣡\n");
	if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");
	if((int)me->query_skill("sword") < 100)
		return notify_fail("��Ľ�������������ʹ����һ�л������ѣ�\n");
	if((int)me->query_skill("force") < 100)
		return notify_fail("����ڹ����Ӳ��ã����ѻû�����â��\n");
	if((int)me->query_skill("unarmed") < 100)
		return notify_fail("����Ʒ�����������ʹ����һ�л������ѣ�\n");
	if(me->query_temp("no_sword"))
		return notify_fail("��ոշ�����â����Ҫ�����������ˣ�\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIC"\n$Nһ����ȣ�˫�ƺ�Ȼ�ų����ຮ�⣬ֱ��$n\n"NOR,me,target);
	ap=(int)me->query("combat_exp");
	dp=(int)target->query("combat_exp");
	damage=random((int)me->query_skill("unarmed"))+random((int)me->query_skill("force"))+random((int)me->query_skill("sword"));
	if (random(ap)>dp/2)
	{
		target->receive_damage("kee",damage);
		COMBAT_D->report_status(target);
	}
	else {
		message_vision(HIW"\n$n�����ո�����ǿ�ܿ�����һ����\n"NOR,me,target);
	}
	me->add("force", -100);
	me->set_temp("no_sword",1);
	call_out("sword_ok",1+random(2),me);
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	return 1;
}

void sword_ok(object me)
{
	if (!me) return;
	me->delete_temp("no_sword");
}
