// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,lvl;
   object weapon, ob;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
       return notify_fail("��С԰�վա�ֻ����ս����ʹ�á�\n");
        weapon = me->query_temp("weapon");
   if((int)me->query("max_force") < 1200)
   return notify_fail("�������̫����!\n");
   if((int)me->query("force") < 500)
   return notify_fail("�������������!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("������½���������ׯ�۹�������ָ�����!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("���彣��������ׯ�۹�������ָ�����!\n");
      if((int)me->query_skill("sword",1) < 210)      return notify_fail("��Ļ�����������!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("˫�����������۫����������ϲ��ܷ�������!\n");

   if( target->is_busy() )
    return notify_fail(target->query("name")+"�Ѿ�ȫ������,����������!\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
 	lvl = (int)me->query_skill("sanqing-jian",1)/40;
 msg = HIC

"\n$N������,Ʈ�����,��̬��Ȼ����,��������$n��������������!\n"
"�ҽ�ȴ������Ϣ���Ƶ�$n����,���ط�ת����,����һ��С԰�վ�!!\n\n" NOR;
        if( random(myexp * lvl) > yourexp )
        {
      msg += HIG
"\nֻ����������,$n����,С�����ļ���Ѩ����ͬʱ����������!!\n"
"$nֻ��ȫ��һ��,��ʱ��������..\n\n" NOR;
                target->start_busy(3+random(3));
        }
   else {
  msg += CYN
"\nֻ���ö�������ʮ��������,�������ø��ֵķ�����ָҲ�޴˼���!!\n"
"$n���еı���ʼ��û����,���ڽ���һʮ���¼������˹���.\n\n" NOR;
                        me->start_busy(2);
}
message_vision(msg, me, target);
        return 1;
}
