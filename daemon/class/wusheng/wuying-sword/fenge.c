#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int mypot,tapot,damage_pot,damage;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ���ָ���ء���\n");

        if(!me->is_fighting())
                return notify_fail("���ָ���ء�ֻ����ս����ʹ�ã�\n");
        if(me->query("family/family_name")!="��ʥ��"
	&& !me->query("guild") )
                return notify_fail("������ʥ�ŵĲ����á��ָ���ء���\n");
        if((int)me->query("max_force") < 200 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 100 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
	if((int)me->query_skill("feisheng-spells", 1) < 50)
		return notify_fail("��ķ����󷨵ȼ�����������ʹ����һ�У�\n");

	me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIY"\n$N����˫Ŀ��ʹ��һ�С��ָ���ء�������"+NOR+HIW+weapon->name()+NOR+HIY"������䣬�ڿշ���ֱն$n��\n\n"NOR,me,target);

	mypot=(int)me->query_skill("sword");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));
	
        tapot=((int)target->query_skill("dodge")+(int)target->query_skill("parry"))/2;
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));      
        
        damage_pot=(int)me->query_skill("wuying");           
        
	if ( random(mypot) > random(tapot) )
	
	{
	  target->receive_damage("kee",damage);
	  me->receive_damage("sen", 100);
          me->add("force", -100);
          me->start_busy(1); 
          COMBAT_D->report_status(target);
        
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

   
