// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// mihun.c �Ի���
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
   string msg;
   int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

       if( (string)me->query("gender") !="Ů��")
       return notify_fail("���Ϊ����֮��,����֪��Ů���ҵ���˼??\n");

   if( !target ) target = offensive_target(me);

   if((int)me->query_skill("spells") < 100 || (int)me->query_skill("xuanhu-shentong",1) < 60)
     return notify_fail("�㻹ûѧ���Ի���������\n");

   if( !target
   ||      !target->is_character()
   ||      target->is_corpse()
   ||      target==me)
     return notify_fail("������˭�Ļꣿ\n");  

   if(target->query_temp("no_move"))
   return notify_fail(target->query("name")+"�Ѿ��겻���ᣬ����ľѼ�ˣ�\n");  

   if((int)me->query("mana") < 200 )
     return notify_fail("��ķ���������\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("���޷����о�����\n");

   me->add("mana", -200);
   me->receive_damage("sen", 10);

   msg = HIC
"$N�����õ�����$n��������۽�$n���ڻ��\n" 
NOR;

   success = 1;
   ap = me->query_skill("spells");
   ap = ap * ap * ap /12 ;
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
   ap2 = (int)me->query_per();
   dp2 = (int)target->query_per();
   ap3 = (int)me->query("mana");
   dp3 = (int)target->query("mana");
 if( (string)target->query("gender") !="����") 

{if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+4000*dp2+400*dp3) )
     success = 0;}
if( (string)target->query("gender") =="����")
{if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2000*dp2+200*dp3) )
        success = 0;}
 
  if(success == 1 ){
     msg +=  HIB "$nէ���������㣬���ɵ��������ԣ�����Χһ�о���Ȼ������\n" NOR;
     target->set_temp("no_move", 1);
   
     howlong = random((me->query_skill("spells") -105)+1);
     if(howlong>60) howlong=60;
     call_out("free", howlong, target);
   }       
   else {
     msg +=  HIR "$n���ĵؿ���$Nһ�ۣ��ȵ����������ÿ���\n" NOR;   
     me->start_busy(2+random(1));        
     target->kill_ob(me);
   } 

   message_vision(msg, me, target);

   return 1;
}

void free(object target)
{
   if (target)
   target->delete_temp("no_move");      
   return;
}

