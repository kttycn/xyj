// Room: some place in 西牛贺洲

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "太极阵");
	set("long", @LONG
此阵乃老君劈地开天，分清理浊，定地水火风，包罗万象之宝-太极图所化而成。
此阵变化无穷，到处弥漫着金色的云彩。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"room",
	]));

	setup();
}

/* void init()
{
	add_action("do_arrest","arrest");   
}

int do_arrest(string arg)
{
       string msg;
       int ap,dp,success;
       object me,target;
       
       me=this_player();       
       if(!arg||arg=="")return 1; 
       if(me->query_temp("taiji_arrest")){
           notify_fail("你已经抓了一个人！\n");
           return 1;
       }       
                
       msg = HIC
        "$N口中念了句咒文，朝空中一指：黄巾力士何在！\n" 
        NOR;
        
        message_vision(msg, me);        
    if(!objectp(target = find_living(arg))|| !environment(target)){
            tell_room(environment(me),"半空中现出一朵金色云彩，一个黄巾力士拱手行礼：禀法主，找不到这个人！\n");
            return 1;
        }
        msg = HIC
        "速去将$n抓来！\n半空中现出一朵金色云彩，一个浑身金甲的黄巾力士现出身形：是！然后就风驰电掣般地去了。\n"
        NOR;

        message_vision(msg,me,target);
      
        me->add("mana", -600);
        me->receive_damage("sen", 30);

        success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared exp and spells level. 
        //note: has nothing to do with target's spells level.
      if(success == 1 ){
          tell_room(environment(target),"空中伸出一只大手将"+target->query("name")+"抓走了。\n");       
          target->move(environment(me));
          msg =  HIR "不一会儿，金色云彩陡现，黄巾力士将$n往地上一扔，把$n摔了个头晕脑胀\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1);
          
          call_out("blowing",1,me,target);
      }       
      else {
         msg =  HIR "不一会儿，半空传来黄巾力士大叫：请法主赎罪，我无法抓获$n！\n" NOR;   
         message_vision(msg,me,target);         
         me->start_busy(1);
      } 
      return 1;
}

void blowing(object me,object target)
{
  int ap,dp,damage;
  string msg;
        
  if(!me||!target||environment(me)!=this_object()||environment(target)!=this_object()){
        remove_call_out("blowing");
        return;
  }
    
  if(random(2)){
    msg = HIC
         "\n半空中金云翻腾，走出一位尖头鹰鼻的雷公，左手执斧，右手提锥。
         斧锥相击，在$n的头顶炸起一片响雷！\n"NOR;

    ap = me->query_skill("spells");
    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp ) {
       damage = (int)me->query("max_mana") / 10 +
           random((int)me->query("eff_sen") / 5);
       damage -= (int)target->query("max_mana") / 10 +
           random((int)target->query("eff_sen") / 5);                   
       damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
//here we can see if 2 players are at same status, the attacker has higher chance.
       if( damage > 0 ) {
           msg +=  HIR "\n$n被雷声震的眼冒金星，心神不定，差点跌倒在地！\n" NOR;
          //finally damage also depends on enabled spells level.
           damage +=random((damage*(int)me->query_skill("spells"))/100);
                        target->receive_damage("sen", damage/5, me);
                        target->receive_wound("sen", damage/10, me);
         }else msg += "\n谁知$n毫无反应，依旧一心一意地和$N战斗。\n";
    }else msg += "\n谁知$n毫无反应，依旧一心一意地和$N战斗。\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n半空中金云翻腾，走出一位容貌秀雅的电母，双手各持一枚铜镜。
     铜镜相转，忽的闪出一道金光射向$n！\n" NOR;

     ap = me->query_skill("spells");
     ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
     ap += (int)me->query("combat_exp");
     dp = target->query("combat_exp");
     if( random(ap + dp) > dp ) {
         damage = (int)me->query("max_mana") / 10 +
            random((int)me->query("eff_sen") / 5);
         damage -= (int)target->query("max_mana") / 10 +
            random((int)target->query("eff_sen") / 5);                   
         damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
         //here we can see if 2 players are at same status, the attacker has higher chance.
         if( damage > 0 ) {
            msg +=  HIR "\n结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血箭，直射到两三丈外的地下！\n" NOR;
            //finally damage also depends on enabled spells level.
            damage +=random((damage*(int)me->query_skill("spells"))/100);
            target->receive_damage("kee", damage/5, me);
            target->receive_wound("kee", damage/10, me);
          }else msg += "\n但是被$n躲开了。\n";
      }
      else msg += "\n但是被$n躲开了。\n";
      message_vision(msg, me, target);
  }
  call_out("blowing",5,me,target);      
}

void reset()
{
        ::reset();
        remove_call_out("blowing");
}

int valid_leave(object me, string dir)
{
        remove_call_out("blowing");
        return 1;
}
}  */
