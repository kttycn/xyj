//bawang-qiang, perform meihua
// /daemon/class/fighter/bawang-qiang/meihua
//÷������ Ҫ�����ǹ��70����110���Ժ��6��
//writted by jie 2001-2-10
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("bawang-qiang", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�÷����������\n");

        if(!me->is_fighting())
                return notify_fail("��÷��������ֻ����ս����ʹ�ã�\n");
                
        if(me->query("family/family_name") != "������" 
	&& !me->query("guild") )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�÷��������?\n");
	
//	if( me->query("pfm_meihua_on") != 1 )
//		return notify_fail("�㻹���ᡸ÷����������\n");                
                
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="spear")
                return notify_fail("��÷��������Ҫ��ǹ���ܷ���������\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 300 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ����㣬û����ʩչ÷��������\n");

        if(myskill < 40)
                return notify_fail("��İ���ǹ�����𻹲�����\n");
        else 
            if(myskill <70){
                times = 3;        
                number = "��";}
            else
                if (myskill <90){
                    times = 4;
                    number = "��";}
                else
                    if(myskill <110 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("spear"));

message_vision(HIC"\n$Nһ����Х��"+ weapon->query("name")+ HIC"��һת�������������$n������"+number+"ǹ��ǹǹҪ����\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 20);
        me->add("force", -(times*50+50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>5)
	{

                target->receive_damage("sen",damage,me);
                target->receive_wound("sen", random(damage), me);
                target->receive_damage("kee",damage+1,me);
                target->receive_wound("kee", random(damage), me);
                  			
		message_vision(HIR"\n$nֻ������ǰһ�����ؿ��ѱ�$N��"+ weapon->query("name")+ HIR"����һ����õ�����÷��������\n\n����������Ѫ��ӿ��������$n�Ѿ���Ϣ���٣���\n" NOR,me,target);
		COMBAT_D->report_status(target, 0);
	}
        me->start_busy(2+random(3));
        return 1;
}
