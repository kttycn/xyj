// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int ap, bp, cp, myexp, yourexp;
        object weapon, ob;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("����ǰ���¡�ֻ����ս����ʹ��.\n");
weapon = me->query_temp("weapon");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("˫�����������۫����������ϲ��ܷ�������!\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("������½���������ׯ�۹�������ָ�����!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("���彣��������ׯ�۹�������ָ�����!\n");
      ap = (int)me->query_skill("xiaofeng-sword",1);
      if((int)me->query_skill("sanqing-jian",1) < 210)
      return notify_fail("������彣�ȼ�������!\n");
      if((int)me->query_skill("xiaofeng-sword",1) < 210)
      return notify_fail("���������½��ȼ�������!\n");
      if((int)me->query_skill("sword",1) < 210)
      return notify_fail("��Ļ�����������!\n");
      if((int)me->query("force") < 500)
      return notify_fail("�������������!\n");   
      if((int)me->query("max_force") < 1200)
      return notify_fail("�������̫����!\n");
    msg = HIC
"\n$Nһ������,������Ȼ���Ѹ���쳣,���潣���Ƶ�,��������,���ǡ���Ů���Ľ�����!!\n" NOR;
message_vision(msg, me, target);
  me->delete("env/brief_message");
   target->delete("env/brief_message");
   me->set_temp("XFS_perform",9);
   COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
me->delete_temp("XFS_perform");
   me->add("force",-100);  
   me->start_busy(1);

        return 1;
}
