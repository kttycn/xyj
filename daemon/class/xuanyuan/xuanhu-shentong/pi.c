
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg,start;
   int ap, dp, success;
   target = offensive_target(me);
   //always use the one who is fighting me as target.

   if( me->is_busy())
     return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

   if( (int)me->query("mana") < 100 )

     return notify_fail("��ķ��������ˣ�\n");

   if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
     return notify_fail("�㾫��̫����Լ��о������䡣\n");
   if(me->query("family/family_name") != "��ԯ��Ĺ"
	&& !me->query("guild") )
   return notify_fail("�����Ǻ���,�Ų�����ô����ƨ!\n");
   if( (int)me->query_skill("xuanhu-shentong", 1) < 20)
     return notify_fail("��δ��ѧ��ƨ�ݡ�\n");

   ap=me->query_skill("spells")+me->query("max_mana")/10;
   if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

   if(!me->is_fighting() )
   {
     message_vision(YEL"$N����ƨ�ɣ���������ͷ��˼�����ƨ��\n"NOR,me);
     me->add("sen", -me->query("max_sen")/8);
     me->add("mana", -80);
     success=1;
   }
   else
   {
     msg=YEL"$NͻȻ����սȦ��ƨ��һ�ᣬһ�ɳ������������\n"NOR;

     if(random(ap+dp)>dp/2)
     {
        msg+=YEL"ֻ��$N����һ�����ߣ�������Ӱ�Ѿ�������.$nȴ����ƨѬ��ҡҡ��׹��\n"NOR;
        me->add("sen", -me->query("max_sen")/6);
        me->add("mana", -50);
        if(target) target->add("sen",-80);
        success=1;
        me->remove_all_killer();
     }
     else msg+=YEL"��$nһ��üͷ��һ��ץס$N��β�͡�\n"NOR;
     me->add("mana", -50);
     message_vision(msg, me, target);
   }
   if(success)
   {
     start=me->query("env/destination");
     start=me->query("�Ǻ�/"+start);
     if(!start || !find_object(start))
        start=me->query("startroom");
     if(!start) start="/d/xuanyuan/yongdao";
     me->move(start);
     message("vision", YEL+me->name()+"ͻȻ��һƬ���������˳���\n"NOR,
            environment(me), me);
     tell_object(me, YEL"�����ӰͻȻ������һƬ�����С�\n"NOR);
     return 3+random(3);
   }
   return 5+random(5);
   //if failed, can't use for a while.
}