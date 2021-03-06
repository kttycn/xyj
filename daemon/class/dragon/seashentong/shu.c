// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg,start;
   int ap, dp, success;
   target = offensive_target(me);

   if( me->is_busy())
     return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

   if( (int)me->query("mana") < 100 )
     return notify_fail("你的法力不够了！\n");

   if ( me->query_temp("in_guard") )
     return notify_fail("你现在正在守门，不能水遁。\n");

   if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
     return notify_fail("你精神太差，难以集中精力念咒。\n");
   if(me->query("family/family_name") != "东海龙宫"
	&& !me->query("guild") )
   return notify_fail("你身非水族,无法水遁!\n");
   if( (int)me->query_skill("seashentong", 1) < 20)
     return notify_fail("你未曾学会水遁(20lv的碧海神通)。\n");


   ap=me->query_skill("spells")+me->query("max_mana")/10;
   if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

   if(!me->is_fighting() )
   {
message_vision("天空忽然下起了倾盆大雨,$N借着雨水化作云雾遁去了. . .\n", me);

     me->add("sen", -me->query("max_sen")/8);
     me->add("mana", -80);
     success=1;
   }
   else
   {
msg=HIC"天空忽然下起了倾盆大雨.....\n"NOR;
     if(random(ap+dp)>dp/2)
     {
        msg+=HIC"只见$N向水幕中一转,不见了人影。\n"NOR;
        me->add("sen", -me->query("max_sen")/6);
        me->add("mana", -50);
        me->remove_all_killer();
        success=1;
     }
     else msg+=HIC"$N刚想变化，那雨却又忽然停了！\n"NOR;
     me->add("mana", -50);
     message_vision(msg, me, target);
   }
   if(success)
   {
     me->move("/d/sea/wolongrest");
     tell_object(me, HIC"你的身影突然出现在水幕中。\n"NOR);
     return 3+random(3);
   }
   return 5+random(5);
   //if failed, can't use for a while.
}

