//jinglei-mace perform lei ����ŭ��
// /daemon/class/fighter/jinglei-mace/lei
// writted by jie 2001-2-10
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg, tparryskill;
        int myskill, myskill1, tparryb, tparryh, myforce, tforce, myexp, texp, damage;
        object weapon,tweapon;
        weapon = me->query_temp("weapon");
        myskill= (int)me->query_skill("mace",1);
        myskill1= (int)me->query_skill("jinglei-mace",1);
        myforce = (int)me->query("force");
        myexp = (int)me->query("combat_exp");
        msg = "";
        if(!objectp(weapon)||(string)weapon->query("skill_type")!="mace")
        	return notify_fail("�������ʹ���ױ޷���");
        if ( myskill1 < 80) return notify_fail("��ľ��ױ޷����������\n");
        if(me->query("family/family_name") != "������" 
	&& !me->query("guild") )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�����ŭ��?\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ŭ��ֻ����ս����ʹ�á�\n");
        if ((int)me->query("force")<300)
                return notify_fail("�������������\n"); 
        tweapon = target->query_temp("weapon");  
        tparryb= (int)target->query_skill("parry",1);
        tforce = (int)target->query("force");
        texp = (int)target->query("combat_exp");
        tparryskill = target->query_skill_mapped("parry");
        tparryh=target->query_skill(tparryskill,1);
        me->add("force",-300);
        me->receive_damage("sen", 20);
     message_vision(HIC"$N��ʽһ��������"+weapon->name()+HIC"�·�����ǧ���Ƶģ�ʹ���˾��ױ޷��ľ�ѧ--������ŭ�𡻣�\n\n" NOR,me,target);        
     message_vision(CYN"$N���˵��ƽƽ�ҳ�һﵣ�����ȴ˻˻������֮����\n"NOR,me);
     message_vision(CYN"��һ�С�����������Ю��������ȴ������է�֣����׺���������\n\n"NOR,me);
     if (random(myexp)>(int)(texp/10) && random(myforce) > (int)(tforce/3)) 
        {
             msg = HIC"$nֻ����һ�ɾ���������һ�㣬���������\n"
                                "���ۡ���һ����$n���һ�����Ѫ���������������ˣ�\n\n"NOR;
	damage= (int)(((int)me->query("max_force")/2+myforce -  (int)target->query("max_force")/2 - tforce)/3);
 	if(damage<1)damage = 1;
 	target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
 	target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     	message_vision(msg, me, target);
     	COMBAT_D->report_status(target);
     	}
     else {
            msg = HIC"$næ�˹��򿹣�����������$N�Ĺ��ƶ���ɢ�ˡ�\n\n"NOR;
            message_vision(msg, me, target);
        }


     message_vision(CYN"$N�ɾ�ת����һ���㼱��磬��̤���ţ�������У��ﵴ�$n���벻���ķ�λ������Ϣ���ҳ���\n" NOR,me,target);
     message_vision(CYN"��һ�С����׵�а�������칫��ŭ��Ҫ��������������������ʹ�ø�ʹ������\n\n" NOR,me,target);
     if(random(myexp)>(int)(texp/10)&& random((int)(myskill + myskill1*3/2))>(int)((tparryb+tparryh)/2))
     {msg = HIC"$n������æ���ң���֪�����ȥ�м��⾲��ˮ��������ﵷ���\n"
        "����Ȼ��$N��"+weapon->name()+HIC"�������У�$n�������±��ҵı������ˣ�\n\n"NOR;
     damage=random(100)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
     target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$nȴ�ľ���ˮ��˿�����Ի��ң����в��У��߽���$N�������Ĺ��ơ�\n\n"NOR;
            message_vision(msg, me, target);
        }


          message_vision(CYN"$NͻȻ��ס���Σ��ز�����������ڱ�������ʤ���У�����ʤ���Ρ�\n"NOR,me);
          message_vision(CYN"��һ�С�����ŭ�𡻰Ѿ��ױ޷��ľ���Ҫּ���ӵغ���ˬ�죡\n\n"NOR,me);
if(random(myexp)>(int)(texp/2))
{msg = HIC"$n��Ȼ�ϵ�����Ϊ$N¶����������ϲ֮�£���æ��ǰ��������\n"
"$N΢΢һЦ����$n����������һ�����価ﵳ���ֱ̽$n���ؿڡ�\n"
"$n���Ӱ��û�������Ͳ���������͸������\n\n"NOR;
damage=(int)(random((int)(myskill1/2))+me->query("force_factor")*3/2);
if(damage<1)damage = 1;
target->receive_damage("kee", me->query("eff_kee")*damage/80, me);
target->receive_wound("kee", me->query("eff_sen")*damage/100, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
else{
         msg = HIC"$n���������е���ʵ�����ƾͼƣ���װ����ǰ��ȴ��$N��ﵵ�һ˲���ڿ�Ծ�������־�����һ�У�\n\n"NOR;
            message_vision(msg, me, target);
        COMBAT_D->do_attack(target, me, tweapon);
        }
        
        me->start_busy(3);
        
     
        return 1;
}








