//Cracked by Roath
//evil...........2000.4.16
#include <ansi.h>
#include <combat.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,j,k,damage,p;
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
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�ʩչ���ž�����\n");

	extra = me->query_skill("lunhui-zhang",1)/10+me->query_skill("staff",1)/10;
		if ( extra < 20) return notify_fail("����ֻ��ȷ�������ȷ����������죬�����޷����ã�\n");

	if(me->query_skill("lotusforce",1) < 100)
		return notify_fail("����ڹ����Ӳ��㣬�޷�������磬ʩչ��������������\n");

	if((string)me->query_skill_mapped("force")!="lotusforce")
		return notify_fail("����������������̨�ķ�Ϊ���ӡ�\n");

	if(me->query("max_force") < 1000)//ԭ��500
		return notify_fail("����������㣬��������Ӷ�һ�����ȡ�\n");
	if(me->query("force") < 1000 )
	   	return notify_fail("�㵱ǰ�������㣬��������Ӷ�һ�����ȡ�\n");
	i=(int)me->query("combat_exp");
	j=(int)target->query_("combat_exp");
	k=(int)me->query_skill("lunhui-zhang",1);

	weapon = me->query_temp("weapon");
me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIY"\n$N����������������֮���һ����磬����"+weapon->name()+NOR+HIY"��Ҳ�����籩������$n������\n"NOR,me,target);
	
	  if (random(i)>random(j)) {
		damage=k/200+(int)me->query("str")/2;//ԭ����k,*7
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/8
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
	if( (int)me->query("force", 1) < 1000 )
	    message_vision(HIY"$N���н���ɬ�ͣ��ղ�һ���ĳ���Ȼ����������ԭ�������������ˣ�\n"NOR,me);

	if (random(i)> random(j)) {
		message_vision(HIY"\n$Nһ���ĳ�����������һ�ȣ�����$n��\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")/2;//ԭ����K
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/6
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
}
	if( (int)me->query("force", 1) < 1000 )
	        message_vision(HIY"$N���н���ɬ�ͣ��ղ�һ�ȴ̳���Ȼ����������ԭ�������������ˣ�\n"NOR,me);
		   
	if (random(i)> random(j)) {
		message_vision(HIY"\n$Nһ��ʹ������Ȼ���֣�����һ����$n��ȥ��\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")/2;//k+random(k)*2+(int)me->query("str")*8
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/8
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
	if( (int)me->query("force", 1) < 1000 )
	    message_vision(HIY"$N���н���ɬ�ͣ��ղ�һ���ֳ���Ȼ����������ԭ�������������ˣ�\n"NOR,me);
	   
	if (random(2)) {
		message_vision(HIY"\n$Nʹ�����һ����ͻȻ���һ����������������ȫ������ע�����б�����$n��ȥ��\n"NOR,me,target);
		damage=k/200+random(k)/100+(int)me->query("str")*1;//damage=k+random(k)*3+(int)me->query("str")*8;
		target->receive_damage("kee",damage);
		target->receive_wound("kee",damage/20);//damage/5
		p = (int)target->query("kee")*100/(int)target->query("max_kee");
		msg = damage_msg(damage, "����");
		msg += "( $n"+eff_status_msg(p)+" )\n";     
		message_vision(msg, me, target);
		me->add("force", -(int)me->query_skill("staff", 1)*2/3); 
		COMBAT_D->do_attack(me, target, weapon);
	}
/*	message_vision(HIY"\n$Nһǹ���أ�����Ծ������һǹ����$n��\n"NOR,me,target);
	damage=k+random(k)*4+(int)me->query("str")*10;
	target->receive_damage("kee",damage);
	target->receive_wound("kee",damage/5);
	p = (int)target->query("kee")*100/(int)target->query("max_kee");
	msg = damage_msg(damage, "����");
	msg += "( $n"+eff_status_msg(p)+" )\n";     
	message_vision(msg, me, target);
//	COMBAT_D->do_attack(me, target, weapon);

	me->receive_damage("sen", 100 );
	me->add("force", -100-(int)me->query("force_factor"));
	me->receive_damage("kee", 30); 
	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
	}
	me->start_busy(7);
	return 5;
}
	msg = HIY  "$N����������������֮���һ����磬����"+ weapon->name()+  "Ҳ�����籩������$n������" NOR;

	message_vision(msg,me,target);
*/
	me->add_temp("apply/attack",extra/4);
	me->add_temp("apply/damage",extra/4);
	lmt = 9;
	for(i=6;i<=lmt;i++)
	{
		me->set_temp("FMZ_perform",i);
		COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR);
	}
	me->receive_damage("sen", 200 );
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);
//	me->add("force",-extra*5);
	me->delete_temp("FMZ_perform");
	me->start_busy(3+random(4));
	return 4;
//}
}