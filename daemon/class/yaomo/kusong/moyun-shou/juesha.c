
#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{       
	string msg;
	int damage, p,time;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("��Ħ�ƾ�ɱ��ֻ����ս����ʹ�á�\n");
     if(me->query("family/family_name")!="���ƶ�"
	&& !me->query("guild") )
           return notify_fail("��Ħ�ƾ�ɱ���ǻ��ƶ��Ĳ���֮�ܣ�\n");
	if( (int)me->query_skill("moyun-shou", 1) < 100 ||
	(int)me->query_skill("unarmed", 1) < 100 )
		return notify_fail("���еĹ��򻹲�����죬����ʹ�á�Ħ�ƾ�ɱ����\n");
/*
        if((int)me->query_skill("huomo-xinfa", 1) <120)
return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������Ħ�ƾ�ɱ����\n");
*/
	if((int)me->query_skill("force", 1) <100)
		return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������Ħ�ƾ�ɱ����\n");
	if (me->query_skill_mapped("unarmed") != "moyun-shou" && 
	me->query_skill("moyun-shou", 1) < 100)
		return notify_fail("�������ڵĿ�����Ϊ��ʹ������Ħ�ƾ�ɱ����\n");
	if( (int)me->query("max_force") < 1200 )
		return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������Ħ�ƾ�ɱ����\n");
	if( (int)me->query("force") < 600 )
		return notify_fail("�������������\n");
	msg = YEL "\n\n$NͻȻ�ٿ�����,���ˡ���һ����һ����ջ���$n���ؿڣ���\n" NOR;
	if (me->query("combat_exp") > target->query("combat_exp")/4)
	{
		me->start_busy(1);
		target->start_busy(1);
		damage = (int)me->query_skill("moyun-shou", 1);
		damage = damage + random(damage/2);
		target->receive_damage("kee", damage,me);
		target->receive_wound("kee", damage/2,me);               
		me->add("force", -(damage/4));
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		if(me->query_skill("moyun-shou", 1) > 119)
			target->set_temp("last_damage_from", me);
		remove_call_out("perform2");
		call_out("perform2", 1, me, target);    
	} else 
	{
		me->start_busy(3);
		me->add("force", -200);	
		msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

// �ڶ���

int perform2(object me, object target)
{
	int damage, p,skill;
	string msg,weapon;
	weapon = me->query_temp("weapon");  
	if(!living(target)) 
		return notify_fail("�����Ѿ�������ս���ˡ�\n");
	if( (int)me->query("force", 1) < 300 )
		return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
	msg = MAG "\n����$NͻȻһ������,бб�˵�,ļ���������,$n��ǰһ��Ӱ!!\n" NOR;
	message_vision(msg, me, target); 
	if (me->query("combat_exp") > target->query("combat_exp")/4)
	{
		msg = CYN "$N����һ��һ��,����֮��,����һ��!!!\n" NOR;
		me->start_busy(1);
		target->start_busy(1);
		damage = (int)me->query_skill("moyun-shou", 1);
		damage = damage+(int)me->query_skill("unarmed", 1);
		damage = damage+(int)me->query_skill("force", 1);
		damage = damage + random(damage*3/2);
		target->receive_damage("kee", damage,me);
		target->receive_wound("kee", damage/2,me);               
		me->add("force", -(damage/4));
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		target->set_temp("last_damage_from", me);
		if(me->query_skill("moyun-shou", 1) > 180)
			remove_call_out("perform3");
		call_out("perform3", 1, me, target);    
	} else 
	{
		me->start_busy(3);
		me->add("force", -200);	
		msg += HIY"����$pͻȻϮ�����ϵ�֮��,�ǵ��㿪���ֹ���,$N�������˸���æ���ҡ�\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

//������

int perform3(object me, object target)
{
	string msg,weapon;
	int p,extra,j;
	j=2+random(3);
    extra = (int)me->query_skill("moyun-shou");
    weapon = me->query_temp("weapon");  
	if( !target ) target = offensive_target(me);
	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("����ӵ�һЦ,�����ջ��������������Ȼ����!!\n");
	if( (int)me->query("force", 1) < 300 )
		return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     
	msg = HIR"\n$N˫�ְ���һ�Ŷ���,����֮��,��Ȼվ��$n��ǰ,
$nֻ�������ϼ,��ס$nȫ��,$N��籩�����������!!\n"NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/dodge", extra);
	me->add_temp("apply/parry", extra);
	for (p=1;p<2+random(2);p++)
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	if( !target->is_fighting(me) ) 
	if( living(target) ) 
		if( userp(target) ) target->fight_ob(me);
	msg = YEL"\n\n$N���ӵ�һЦ,�����ջ��������������Ȼ����!!\n"NOR;
	message_vision(msg, me, target);
    msg = YEL"�����������������,$n��ʱһ��,ѹ������!!\n"NOR;
	message_vision(msg, me, target);
	me->add_temp("apply/parry", -extra);
	me->add_temp("apply/dodge", -extra);
	me->add_temp("apply/attack",-extra);
	me->start_busy(1+random(1));
	if (random(me->query("combat_exp")) > random(target->query("combat_exp")/4))
	{
		if(me->query_skill("moyun-shou", 1) > 250)
			remove_call_out("perform4");
		call_out("perform4", 1, me, target);    
	}
	return 1;
}
int perform4(object me, object target)
{
	int damage, p,skill;
	string msg,weapon;
    weapon = me->query_temp("weapon");  
	if(!living(target)) 
		return notify_fail("�����Ѿ�������ս���ˡ�\n");
	if( (int)me->query("force", 1) < 3000 )
		return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");     
	msg = HBYEL "\n�����ϵ���$N��������֮��,$N˫��һ����������������һ��\n" NOR;
	message_vision(msg, me, target); 
	if (random(me->query("combat_exp")) > random(target->query("combat_exp")/2))
	{
		msg = CYN "$n�������Ѿ���������,$N��������,��ǰ����һȭ\n" NOR;
		me->start_busy(1);
		target->start_busy(1);
		damage = (int)me->query_skill("moyun-shou", 1);
		damage = damage+(int)me->query_skill("unarmed", 1);
		damage = damage+(int)me->query_skill("force", 1);
		damage = damage + random(damage*3/2);
		target->receive_damage("kee", damage*2,me);
		target->receive_wound("kee", damage,me);               
		me->add("force", -(damage/4));
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
	} else 
	{
		me->start_busy(3);
		me->add("force", -200);	
		msg += HIY"����$pͻȻϮ�����ϵ�֮��,�ǵ��㿪���ֹ���,$N�������˸���æ���ҡ�\n"NOR;
        message_vision(msg, me, target);
	}
	return 1;
}
