// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int myexp,yourexp,lvl,ap;
   object weapon, ob;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
       return notify_fail("������ҹ����ֻ����ս��ʹ�á�\n");
        weapon = me->query_temp("weapon");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("������½���������ׯ�۹�������ָ�����!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("���彣��������ׯ�۹�������ָ�����!\n");
      if((int)me->query_skill("sword",1) < 180)      return notify_fail("��Ļ�����������!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("˫�����������۫����������ϲ��ܷ�������!\n");
   if( (int)target->query("force") < 400)
    return notify_fail(target->query("name")+"�Ѿ�������ɢ��!!\n");
   if((int)me->query("max_force") < 1500)
    return notify_fail("�������̫��,������ʩչ������ҹ������\n");
   if((int)me->query("force") < 500)
    return notify_fail("�������������!\n");
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
 	lvl = (int)me->query_skill("sanqing-jian",1)/30;
 	ap = (int)me->query_skill("xiaofeng-sword",1)*3;
 msg = HIC

"\nֻ��$N����ƮƮ,��������,��������������߰�����$n��ȫ�����߲���!\n"
"����˫��ͬ��һ�С�����ҹ����,ȴ���󽣻���$n����Ѩ,�ҽ�����$n�Ժ�����Ѩ!\n\n" NOR;
        if( random(myexp * lvl) > yourexp )
        {
      msg += HIR
"\n˫�����,������ʱ��þ���,$n�����м�,��������,������������.\n"
"$nֻ������һ��,���һ��,ȫ��������й����!!!\n\n" NOR;
        target->add("force",-ap);
        target->start_busy(1+random(1));
        }
   else {
   msg += HIY
"\nֻ����������һ������,$n��������,���ϲ��ɱ�ɫ.\n"
"ԭ����������������ʮ���±����ཻ֮�����,,�ʲŹ���֮��,�ɴ˿ɼ�һ��!!\n\n" NOR;
            me->add("force",-150);
            me->start_busy(1+random(1));
}
message_vision(msg, me, target);
        return 1;
}
