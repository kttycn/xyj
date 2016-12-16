// Room: some place in ��ţ����

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
�������Ͼ����ؿ��죬�������ǣ�����ˮ��磬��������֮��-̫��ͼ�������ɡ�
����仯������������Ž�ɫ���Ʋʡ�
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
           notify_fail("���Ѿ�ץ��һ���ˣ�\n");
           return 1;
       }       
                
       msg = HIC
        "$N�������˾����ģ�������һָ���ƽ���ʿ���ڣ�\n" 
        NOR;
        
        message_vision(msg, me);        
    if(!objectp(target = find_living(arg))|| !environment(target)){
            tell_room(environment(me),"������ֳ�һ���ɫ�Ʋʣ�һ���ƽ���ʿ�����������������Ҳ�������ˣ�\n");
            return 1;
        }
        msg = HIC
        "��ȥ��$nץ����\n������ֳ�һ���ɫ�Ʋʣ�һ�������׵Ļƽ���ʿ�ֳ����Σ��ǣ�Ȼ��ͷ�۵糸���ȥ�ˡ�\n"
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
          tell_room(environment(target),"�������һֻ���ֽ�"+target->query("name")+"ץ���ˡ�\n");       
          target->move(environment(me));
          msg =  HIR "��һ�������ɫ�Ʋʶ��֣��ƽ���ʿ��$n������һ�ӣ���$nˤ�˸�ͷ������\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1);
          
          call_out("blowing",1,me,target);
      }       
      else {
         msg =  HIR "��һ�������մ����ƽ���ʿ��У��뷨��������޷�ץ��$n��\n" NOR;   
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
         "\n����н��Ʒ��ڣ��߳�һλ��ͷӥ�ǵ��׹�������ִ����������׶��
         ��׶�������$n��ͷ��ը��һƬ���ף�\n"NOR;

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
           msg +=  HIR "\n$n�����������ð���ǣ����񲻶����������ڵأ�\n" NOR;
          //finally damage also depends on enabled spells level.
           damage +=random((damage*(int)me->query_skill("spells"))/100);
                        target->receive_damage("sen", damage/5, me);
                        target->receive_wound("sen", damage/10, me);
         }else msg += "\n˭֪$n���޷�Ӧ������һ��һ��غ�$Nս����\n";
    }else msg += "\n˭֪$n���޷�Ӧ������һ��һ��غ�$Nս����\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n����н��Ʒ��ڣ��߳�һλ��ò���ŵĵ�ĸ��˫�ָ���һöͭ����
     ͭ����ת����������һ���������$n��\n" NOR;

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
            msg +=  HIR "\n������͡���һ��������$n����͸�������\n�ϳ�һ��������Ѫ����ֱ�䵽��������ĵ��£�\n" NOR;
            //finally damage also depends on enabled spells level.
            damage +=random((damage*(int)me->query_skill("spells"))/100);
            target->receive_damage("kee", damage/5, me);
            target->receive_wound("kee", damage/10, me);
          }else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
      }
      else msg += "\n���Ǳ�$n�㿪�ˡ�\n";
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
