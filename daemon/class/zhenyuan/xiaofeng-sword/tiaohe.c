// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void remove_effect(object me, int amount);

string msg;
int perform(object me, object target)
{
        int skill;
        object ob;

        skill = me->query_skill("sanqing-jian",1);

   if( skill > 250 ) {
     skill=250;
   }
  if( (int)me->query("force") < skill*2 )
  return notify_fail("�������������\n");
  if( (int)me->query_temp("tiaohe") )
  return notify_fail("���Ѿ����˹����ˡ�\n");
  if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      !me->is_fighting(target) )
 return notify_fail("���رߵ��ס�ֻ����ս����ʹ�á�\n");
     if(! me->query("sword_xiaofeng") == 1 ) 
    return notify_fail("������½���������ׯ�۹�������ָ�����!\n");
     if(! me->query("sword_sanqing") == 1 ) 
    return notify_fail("���彣��������ׯ�۹�������ָ�����!\n");
      if((int)me->query_skill("sword",1) < 180)
      return notify_fail("��Ļ�����������!\n");
   if((!objectp(ob = present("doublesword", me)) )|| (!ob->query("equipped")))
    return notify_fail("˫�����������۫����������ϲ��ܷ�������!\n");

        me->add("force", -skill);

         msg = HIR
"\n$N˫������ת��,��������֯��һ������,����һ�й��ؼ汸�ġ��رߵ��ס�!\n"
"ɲ�Ǽ佣���ݺ�,������,�Ƶ�$n���ҽ���벽.\n\n" NOR;
        msg += HIG
"\n���ð���,����$Nһ����Х,���γ������,�����ʱ��ɢ��ȥ.\n"
"ֻ����������ɫ�Ĺ�â��ס$N��˫��,$N�е�����첻��!\n\n" NOR;
     message_vision(msg, me, target);
   me->add_temp("apply/dodge",skill/3);
   me->add_temp("apply/attack",skill/3);
        me->set_temp("tiaohe", 1);

me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);


        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("tiaohe");
   // mon 3/1/98. move this to after powerup is done.
        tell_object(me, HIG"��������������һ�������,��â������ȥ.\n"NOR);
}

