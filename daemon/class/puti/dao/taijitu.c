// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// taiji.c
#include <ansi.h>

inherit SSERVER;

void end_cast(object me,object target);
void cast_person(object me,object target);

int cast(object me, object target)
{
	string msg;
	int howlong;

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ��˭ʩչ̫��ͼ��\n");

	if(me->query("family/family_name")!="����ɽ���Ƕ�"
	&& !me->query("guild") )
		return notify_fail("���ǵ��ҵ��Ӳ����á�̫��ͼ����\n");

	if(!me->query("taoist/taijitu_known"))
		return notify_fail("�㻹ûѧ��ʹ��̫��ͼ������\n");
	if((int)me->query_skill("spells") < 300)
	    return notify_fail("�㻹������������̫��ͼ��\n");
	if( me->query_temp("cast_taiji"))
		return notify_fail("���Ѿ���ʹ��̫��ͼ��\n");	

	if((int)me->query("mana") < 2000 )
		return notify_fail("��ķ���������\n");
	if((int)me->query("sen") < 500 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -1500);
	me->receive_damage("sen", 300);
	if( random(me->query("max_mana")) < 500 ) {
		write("��ʧ���ˣ�\n");
		return 1;
	}
	
	msg = HIC
	"\n$N�������˾����ģ����һ����߾��������̫�����Σ�������\nֻ�����н��ƶ��𣬲�Ѹ��������������$N��������ȥ��\n"
	NOR;
	message_vision(msg,me,target);
	me->set("env/invisibility", 1);
	howlong=me->query_skill("spells")/5;
	if(howlong>60)howlong=60;
	me->set_temp("cast_taiji",1);
    cast_person(me,target);
	call_out("end_cast",howlong,me,target);
    environment(me)->set("oldlong",environment(me)->query("long"));
	environment(me)->set("long", environment(me)->query("oldlong")+"\n����������Ž�ɫ���Ʋʣ�һ�о�ɫ����ģ����\n\n");

	if( !target->is_fighting(me) ) {
		if( living(target) ) {
			if( userp(target) ) target->fight_ob(me);
			else target->kill_ob(me);
		}
		me->kill_ob(target);
	}

	
	me->start_busy(1);
	return 3+random(5);
}

void cast_person(object me,object target)
{
	int ap,dp,damage;
	string msg;

	if(!target||environment(target) != environment(me)||!me->is_fighting(target)){
		remove_call_out("cast_person");
		remove_call_out("end_cast");
		end_cast(me,target);
		return;
	}
	if (target)     target->delete_temp("no_move");
	if(random(2)){
		msg = HIC"\n����н��Ʒ��ڣ��߳�һλ��ͷӥ�ǵ��׹�������ִ����������׶��
��׶�������$n��ͷ��ը��һƬ���ף�\n"NOR;

		ap = me->query_skill("spells");
	    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    	ap += (int)me->query("combat_exp");
	    dp = target->query("combat_exp");
    	if( random(ap + dp) > dp ) {
			damage = (int)me->query("max_mana") / 10 +
			random((int)me->query("eff_sen") / 5);
			damage -= (int)target->query("max_mana") / 10 +
			random((int)target->query("eff_sen") / 5);		   
			damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
			if( damage > 0 ) {
				msg +=  HIR "\n$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR;
				target->set_temp("no_move",1);
	  //finally damage also depends on enabled spells level.
				damage +=random((damage*(int)me->query_skill("spells"))/200);
				target->receive_damage("sen", damage/4, me);
				target->receive_wound("sen", damage/8, me);
			}else msg += "\n˭֪$n���޷�Ӧ������һ��һ��غ�$Nս����\n";
		}else msg += "\n˭֪$n���޷�Ӧ������һ��һ��غ�$Nս����\n";     
		message_vision(msg, me, target);
	}else {
		msg = HIC"\n����н��Ʒ��ڣ��߳�һλ��ò���ŵĵ�ĸ��˫�ָ���һöͭ����
ͭ����ת����������һ���������$n��\n" NOR;

		ap = me->query_skill("spells");
		ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
		ap += (int)me->query("combat_exp");
		dp = target->query("combat_exp");
		if( random(ap + dp) > dp ) {
			damage = (int)me->query("max_mana") / 10 +
			random((int)me->query("eff_sen") / 5);
			damage -= (int)target->query("max_mana") / 10 +
			random((int)target->query("eff_sen") / 5);		   
			damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
	 //here we can see if 2 players are at same status, the attacker has higher chance.
			if( damage > 0 ) {
				msg +=  HIR "\n������͡���һ��������$n����͸�������\n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR;
				target->set_temp("no_move",1);
	    //finally damage also depends on enabled spells level.
				damage +=random((damage*(int)me->query_skill("spells"))/200);
				target->receive_damage("kee", damage/6, me);
				target->receive_wound("kee", damage/10, me);
			}else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
		}
		else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
		message_vision(msg, me, target);
	}
	call_out("cast_person",5,me,target);    	
}

void end_cast(object me,object target)
{
    string msg;
    	
    msg = HIC
     "\n����н��ƽ�����ɢ�ˣ�¶����$N����Ӱ��\n" NOR;
    message_vision(msg,me);
    me->set("env/invisibility", 0);
if (target)     target->delete_temp("no_move");
    if(environment(me)->query("oldlong"))
       environment(me)->set("long",environment(me)->query("oldlong"));
    me->delete_temp("cast_taiji");
    remove_call_out("cast_person");	
}
