// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg,start;
   int ap, dp, success;
   target = offensive_target(me);

   if( me->is_busy())
     return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

   if( (int)me->query("mana") < 100 )
     return notify_fail("��ķ��������ˣ�\n");

   if ( me->query_temp("in_guard") )
     return notify_fail("�������������ţ�����ˮ�ݡ�\n");

   if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
     return notify_fail("�㾫��̫����Լ��о������䡣\n");
   if(me->query("family/family_name") != "��������"
	&& !me->query("guild") )
   return notify_fail("�����ˮ��,�޷�ˮ��!\n");
   if( (int)me->query_skill("seashentong", 1) < 20)
     return notify_fail("��δ��ѧ��ˮ��(20lv�ı̺���ͨ)��\n");


   ap=me->query_skill("spells")+me->query("max_mana")/10;
   if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

   if(!me->is_fighting() )
   {
message_vision("��պ�Ȼ�������������,$N������ˮ���������ȥ��. . .\n", me);

     me->add("sen", -me->query("max_sen")/8);
     me->add("mana", -80);
     success=1;
   }
   else
   {
msg=HIC"��պ�Ȼ�������������.....\n"NOR;
     if(random(ap+dp)>dp/2)
     {
        msg+=HIC"ֻ��$N��ˮĻ��һת,��������Ӱ��\n"NOR;
        me->add("sen", -me->query("max_sen")/6);
        me->add("mana", -50);
        me->remove_all_killer();
        success=1;
     }
     else msg+=HIC"$N����仯������ȴ�ֺ�Ȼͣ�ˣ�\n"NOR;
     me->add("mana", -50);
     message_vision(msg, me, target);
   }
   if(success)
   {
     me->move("/d/sea/wolongrest");
     tell_object(me, HIC"�����ӰͻȻ������ˮĻ�С�\n"NOR);
     return 3+random(3);
   }
   return 5+random(5);
   //if failed, can't use for a while.
}

