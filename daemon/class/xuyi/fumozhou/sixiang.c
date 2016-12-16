//sixiang.c ��������
#include <ansi.h>

inherit SSERVER;

void npc_attack(object invoker, object target, string npc, object where);

int cast(object me, object target)
{
	string msg;
	string npc_dir = "/d/xuyi/npc/";
	object where;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("���������˭��\n");

	if((string)me->query("family/family_name") != "����ɽ" 
	&& !me->query("guild") )
		return notify_fail("���ֲ�������ɽ���ӣ��벻���Ĵ��񽫡�\n");

	if((string)target->query("family/family_name") == "����ɽ" )
		return notify_fail("ͬ���භҲҪ���Ĵ��񽫣�\n");

	if((int)me->query_skill("fumozhou", 1) < 20)
		return notify_fail("��ķ�ħ����Ϊ����ڲ���������\n");
	
	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������û�취��������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("���������ǲ��壬����Ҳ���Ǹ����õ�ѡ��\n");

	me->add("mana", -200);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) 
	{
		write("�ף���һ�κ����顣\n");
		return 1;
	}

	msg = HIC "$N���һ�������񽫣�����\n"+
			 "���������Ĵ��񽫴��������˳��������ء�ˮ���𡢷��ĸ���λ������ƣ�\n"+"��$n����Χס��\n\n" NOR;	
	message_vision(msg, me, target);
	msg = "$n����$N�����������ҽ������ң��������㣡\n" NOR;	
	message_vision(msg, me, target);
	target->kill_ob(me);
	
	where=environment(target);
	call_out("npc_attack", 2, me, target, npc_dir+"zhao", where);
	call_out("npc_attack", 3, me, target, npc_dir+"qian", where);
	call_out("npc_attack", 5, me, target, npc_dir+"sun", where);
	call_out("npc_attack", 6, me, target, npc_dir+"wang", where);
	me->start_busy(2+random(2));
	return 3+random(10);
}

void npc_attack(object invoker, object target, string npc, object where)
{
	object attacker;

	if(!invoker || !target) return;

	if( environment(invoker) != environment(target) ) return;
	if( environment(target) != where) return;

	seteuid(getuid());
	attacker = new(npc);
	attacker->move(environment(invoker));

	COMBAT_D->do_attack(attacker, target, attacker->query_temp("weapon"));
	
	// give the killing credit to the invoker.
	// so this would be counted as PK if the invoker is user.
	// mon 4/11/98
	if(target->query_temp("last_damage_from")==attacker)
		 target->set_temp("last_damage_from", invoker);
	
	if(target->query_temp("last_fainted_from")==attacker)
		 target->set_temp("last_fainted_from", invoker->query("id"));

	destruct(attacker);
}
