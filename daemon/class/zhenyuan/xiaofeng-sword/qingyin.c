#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
 string msg;
 object ob;
 object weapon2;
 int skill, ap, myexp, yourexp;

 me->clean_up_enemy();
 target = me->select_opponent();

  skill = (int)me->query_skill("sanqing-jian",1);

 if( !(me->is_fighting() ))
  return notify_fail("������С�á�ֻ����ս����ʹ�á�\n");

 if (!objectp(weapon2 = target->query_temp("weapon")))
  return notify_fail("�Է�û��ʹ����, ���ò��ˡ�����С�á���\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("˫�����������۫����������ϲ��ܷ�������!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("������½���������ׯ�۹�������ָ�����!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("���彣��������ׯ�۹�������ָ�����!\n");
      if((int)me->query_skill("sanqing-jian",1) < 210)
      return notify_fail("������彣�ȼ�������!\n");
      if((int)me->query_skill("xiaofeng-sword",1) < 210)
      return notify_fail("���������½��ȼ�������!\n");
      if((int)me->query_skill("sword",1) < 210)
      return notify_fail("��Ļ�����������!\n");
 if( (int)me->query("max_force") < 1200)
 return notify_fail("�������̫��,����������С��!\n");
 if( (int)me->query("force") < 500)
 return notify_fail("�������������!!\n");

     msg = HIC
"\n$Nһ�С�����С�á�,�󽣽�������,������ָ,��������þ�!\n"
"�ҽ�ȴ�ǽ����Ϸ�,����ָ�����ѵĿڴ�,���ƾٱ�����һ��.\n\n" NOR;

 ap = skill/60+1;
 myexp = (int)me->query("combat_exp");
 yourexp = (int)me->query("combat_exp");
 if( random(myexp*ap) > yourexp)
 {
  if(userp(me))
   me->add("force",-50);
  msg += CYN
"\n$nֻ���Ҽ�һ��,��ʱ�����ֱ�ת������,���Ż���һ��,����";
  msg += weapon2->name();
  msg += "���ֶ���!!\n" NOR;

  target->start_busy(2);
  weapon2->move(environment(me));
        }
 else
 {
  if(userp(me))
   me->add("force",-30);
  msg += HIG
"\n����$n�ƺ��������а���,��ͷ΢��,�㿪���������޷���һ��!!\n" NOR;
  me->start_busy(1+random(1));
 }
 message_vision(msg, me, target);
                                       
 return 1;
} 


