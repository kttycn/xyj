// ��ʯ��� gong.c
//Write by godzilla 99.11.10

inherit SSERVER;

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;

	if( !target )
		target = offensive_target(me);
	if(!me->query("xueshan/yushijufen_perform"))
		return notify_fail("�㻹û���������ž��С�\n");
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("����ʯ��١�ֻ����ս����ʹ�á�\n");
     if(me->query("family/family_name")!="��ѩɽ"
	&& !me->query("guild") )
           return notify_fail("����ʯ��١�ֻ�д�ѩɽ���˲ſ����ã�\n");
	if( (int)me->query("int") < 25 )
		return notify_fail("���Ǻ����ؼ�����һ�������֣������Բ�������ʹ����ʯ��٣�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("max_force") < 1200 )
		return notify_fail("�������������㣬ʹ������ʯ��٣�\n");     
	if( (int)me->query("force") < 200 )
		return notify_fail("�������������㣬ʹ������ʯ��٣�\n");
	if( me->query_temp("bingpo-blade") )
		return notify_fail("���ʹ�꡸���Ǻ������ľ��У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
	msg = HIW "\n$N���б������ʲ�����һ������Χ�Ƶ�����δ���������Ѳ����������µ�һ����\n----��"+BLINK+HIR+"��ʯ���"+NOR+HIW+"����Ȼ���֣����������������ְ��ֱ��$n��ȥ��\n"NOR;
	me->set_temp("bingpo-blade", 1);
	if (random((int)me->query("combat_exp")) > random(target->query("combat_exp") ) )
	{
		damage = (int)me->query_skill("bingpo-blade", 1); 
		damage = damage*2 + random(damage);
		msg += HIR"$p��$P��һ�й��ú��޻���֮����ֻ�����ꡱ��һ����$p����Ѫ�ѽ���ȫ��\n" NOR;
		message_vision(msg,me,target);
		if(me->query("force")>350)
			call_out("perform2",0, me,target);
		call_out("remove_effect",me->query_con()/2, me); 
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/2);
		me->start_busy(1);
		me->add("force", -150);
	} 
	else {
		me->start_busy(2);
		target->start_busy(1);
		me->add("force", -100);
		msg +=HIY"$p��Ȼ�о���$P�����������ƣ����޿ɱ��⡣�������ϣ����˳�ȥ��\n"NOR;
		message_vision(msg, me, target);
		call_out("remove_effect", me->query_con()/6, me);
	}
	return 1;
}

int perform2(object me, object target)
{
	int damage;
	string msg;
	msg = HIW "\n$N����δ�꣬�ڶ����Ѿ������������죬����ʢ����һ����ʯ��٣�\n"NOR;
	if(me->query_int()>= random(50))
	{
		me->start_busy(1);
		target->start_busy(1);
		me->add("force", -300);
		damage = (int)me->query_skill("bingbo-blade", 1);                
		damage = damage*5 + random(damage)*2;
		msg +=HIR"ֻ�����ꡱ��һ����$n�Ѿ�����ҡҡ��׹�ˣ�\n"NOR;
		message_vision(msg, me, target);
		damage += random(damage);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/2);
	}
	else
	{
		msg +=HIY"$n�������������������ϣ��������˳�ȥ!\n"NOR;
		message_vision(msg, me, target);	
		me->start_busy(2);
		target->start_busy(1);
		me->add("force", -100);
	}	
	return 1;
}

void remove_effect(object me)
{
	if (!me) 
		return;
	me->delete_temp("bingpo-blade");
	tell_object(me, HIR"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����Ǻ������ľ����ˡ�\n"NOR); 
}
