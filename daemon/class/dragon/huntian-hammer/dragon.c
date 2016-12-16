#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";
int def;

int perform(object me, object target)
{
	object weapon1;
	string msg;
	int damage, p,time;

	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("���������¡�ֻ����ս����ʹ�á�\n");
	if(me->query("family/family_name") != "��������"
	&& !me->query("guild") )
		return notify_fail("���Ǵ�����͵ѧ���ģ�\n");
	if( !(weapon1 = me->query_temp("weapon"))
	|| (string)weapon1->query("skill_type") != "hammer" )
		return notify_fail("����Ϊ����˭��û��Ҳ���������£�\n");

	if( (int)me->query_skill("hammer", 1) < 100 ||
	(int)me->query_skill("huntian-hammer", 1) < 100 )
		return notify_fail("�㴸����������죬����ʹ�á��������¡���\n");
	if((int)me->query_skill("dodge", 1) <120)
		return notify_fail("�������ڵ��Ṧ��Ϊ��Ρ��������¡���\n");
	if((int)me->query_skill("force", 1) <100)
		return notify_fail("�������ڵ��ڹ���Ϊ��ʹ�������������¡���\n");

	if( (int)me->query("max_force") < 1200 )
		return notify_fail("�������ڵ�������Ϊ��ʹ�������������¡���\n");

	if( (int)me->query("force") < 600 )
		return notify_fail("�������������\n");

	msg = HIY "\n$Nʹ�������ռ��������������¡�������Ȼ�ӿ죡\n" NOR;
	if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3))
	{
		me->start_busy(2);
		target->start_busy(1);
		msg += YEL "\n$N��Ȼ��һ�������մ����裬��$n������ó���\n"NOR;
		if (me->query("str") > random(target->query("str")))
		{
			msg += HIR "\n����$n���һ�������ۺ�������������㴸Ӱ���γɵ�������\n" NOR;
			msg += HIR "���$nֻ���ļ������������У����޷���ά�����ȵ����ơ�\n" NOR;
			damage = (int)me->query_skill("huntian-hammer", 1);
			damage = damage + random(damage);
			def=(int)target->query_temp("apply/armor_vs_force");
			damage -=damage*def/3000;
			target->receive_damage("kee", damage);
			me->add("force", -(damage/4));
			p = (int)target->query("kee")*100/(int)target->query("max_kee");
			msg += damage_msg(damage, "����");
			msg += "( $n"+eff_status_msg(p)+" )\n";
			message_vision(msg, me, target);
			target->set_temp("last_damage_from", me);
			if(me->query_skill("hammer", 1) > 119)
			{
				remove_call_out("perform2");
				call_out("perform2", 0, me, target);
			}
		} else
		{
			msg += HIC "��ʱ�ƺ����ֲ��أ����䲨��״�Ĵ�Ӱ���˻�ǰ�ˣ�һ�˸߹�һ�ˣ����಻����\n"NOR;
			message_vision(msg, me, target);
			for (p=1;p<3+random(3);p++)
	            COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
			if(random(me->query_skill("huntian-hammer", 1))> 119)
			{
				remove_call_out("perform2");
				call_out("perform2", 0, me, target);
			}
		}
	} else {
		me->start_busy(3);
		me->add("force", -200);
		msg += HIG"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
		if(me->query_skill("huntian-hammer",1)>119)
		{
			remove_call_out("perform2");
			call_out("perform2", 0, me, target);
		}
	message_vision(msg, me, target);
	}
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
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("��������������û������ѽ��\n");
	if( (int)me->query("force", 1) < 300 )
		return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");
	if (random(5)>2)
		msg = HIC"\n����$N���ϱ���,ͻȻһ������,���һ��,ļ���������,$n��ǰһ��!!\n"NOR;
	else
		msg = HIG"\n����$N���ϱ���,ͻȻ��Хһ��,�մ���ɨ,���Ƹ���,$n�����Ż����ֽ�!!\n"NOR;
	message_vision(msg, me, target);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
	{
		msg = CYN "$n����֮�£���ʱ����ɢ�ң��޴��мܣ�\n" NOR;
		me->start_busy(2);
		target->start_busy(1);
		damage = (int)me->query_skill("huntian-hammer", 1);
		damage = damage+(int)me->query_skill("force", 1);
		damage = damage + random(damage);
		def=(int)target->query_temp("apply/armor_vs_force");
		damage -=damage*def/3000;
		target->receive_damage("kee", damage);
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		target->set_temp("last_damage_from", me);
		if(me->query_skill("huntian-hammer", 1) > 179)
		{
			remove_call_out("perform3");
			call_out("perform3", 0, me, target);
		}
	} else {
		me->start_busy(3);
		me->add("force", -200);
		msg = WHT"����$p�ϵ�֮��,�������У�����$N�������ˡ�\n"NOR;
		if(me->query_skill("huntian-hammer", 1) > 179
		&& me->query_skill("hammer", 1) > 179)
		{
			remove_call_out("perform3");
			call_out("perform3", 0, me, target);
		}
	}
	message_vision(msg, me, target);
	return 1;
}
//������
int perform3(object me, object target)
{
	int damage, p,skill;
	string msg,weapon;
	weapon = me->query_temp("weapon");
	if(!living(target))
		return notify_fail("�����Ѿ�������ս���ˡ�\n");
	if( !target || !target->is_character()
	|| !me->is_fighting(target) || !living(target) )
		return notify_fail("��������������û������ѽ��\n");
	if( (int)me->query("force", 1) < 2000 )
		return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");
	if (random(5)>2)
	{
		msg = HIC"\n$Nһ��������������Ȼ���ַɳ����������㰿������ƿ�����$n����磡\n"NOR;
		msg += HIC "$n���һ��������$N���������ϣ�˫�����õ��ģ���������֮��!\n" NOR;
	}
	else
		msg = HIG"\n$N��Хһ����һʽ����غ��衹���ڿշ���ȫ��ų���������Ӱ��������ʣ�\n"NOR;
	message_vision(msg, me, target);
	if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3*2))
	{
		msg = CYN "$n�������Ѿ���������,$N�������һ��\n" NOR;
		me->start_busy(2);
		target->start_busy(1);
		damage = (int)me->query_skill("unarmed", 1);
		damage = damage+(int)me->query_skill("force", 1);
//		damage = damage*(1+random(3))/2+random(damage);
		def=(int)target->query_temp("apply/armor_vs_force");
		damage -=damage*def/3000;
		target->receive_damage("kee", damage);
		me->add("force", -(damage/4));
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg += damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";
		message_vision(msg, me, target);
		target->set_temp("last_damage_from", me);
		me->start_busy(2);
	} else {
		me->start_busy(1+random(2));
		me->add("force", -200);
		msg = HIC"����$pһ������,������$N�����Ľ�����\n"NOR;
		message_vision(msg, me, target);
	}
	me->add("force",-500);
	return 1;
}
