//Modified by vikee for xlqy-zq station
//2000-12-5 10:19

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i,j,e,mypot,tapot,damage_pot,damage,damagea;
	weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	|| !target->is_character()
	|| target->is_corpse()
	|| target==me)
		return notify_fail("��Ҫ����˭��\n");

	if(me->query("family/family_name") != "��ɽ����" 
	&& !me->query("guild") )
		return notify_fail("�����Ķ�͵ѧ�����书��\n");
	if(!me->is_fighting())
		return notify_fail("����û���ڴ�ܣ�\n");

        if((int)me->query("max_force") < 200 )
                return notify_fail("����ڹ�̫�\n");

        if((int)me->query("force") < 100 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
                
	if((int)me->query_skill("taoism", 1) < 100)
		return notify_fail("�����ʦ�ɷ��ȼ�����������ʹ����һ�У�\n");
		
	i=(int)me->query_skill("sword",1);
	j=(int)target->query_skill("dodge",1);
	e=i+j+i/2;
	if(e<200)
		return notify_fail("��Ľ������Ṧ���𻹲�����ʹ����һ�л������ѣ�\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIW"\n$N����Ĭ�������ھ�������"+weapon->name()+NOR+HIW"ϼ�����䣬�ڿշ���һ�С�������ħ��ֱն$n��\n\n"NOR,me,target);

	mypot=i*i*i/10 + random( (int)me->query("combat_exp"));
	
	tapot=((int)target->query_skill("dodge",1)+(int)target->query_skill("parry",1))/2;
	tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));      

	damage_pot=(int)me->query_skill("yujianshu",1);           

	if ( random(mypot) > random(tapot) )	//main condition vikee 2000-12-5 10:11
	{
		damage = i+random((int) me->query("max_force"))/30;
		damagea = i+random((int) me->query("max_force"))/50;
		target->receive_damage("kee",damage);
		target->receive_damage("sen",damagea);
		me->receive_damage("sen", 100);
		me->add("force", -100);
		me->start_busy(1); //busy time is added.    
		COMBAT_D->report_status(target);
		COMBAT_D->report_sen_status(target);
        
		if( !target->is_fighting(me) ) 
		{
			if( living(target) ) 
			{
				if( userp(target) ) target->fight_ob(me);
				else target->kill_ob(me);
			}
		}
	}

	else
	{
		message_vision(HIW"\n$n�����˼��ºò����׶㿪���⼸�����⣡\n\n"NOR,me,target);
		me->start_busy(2);
 	}
	return 1;
}

   
