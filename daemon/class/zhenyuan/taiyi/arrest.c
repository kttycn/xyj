// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// arrest.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if((int)me->query_skill("spells") < 200)
                return notify_fail("�㻹ûѧ���ٻ��ƽ���ʿ������\n");

        if( me->query("family/family_name")!="��ׯ��"
	&& !me->query("guild") )
                return notify_fail("�㲻����ׯ�����£��ƽ���ʿ�ǲ������ġ�\n");
        if( me->query("faith")<4000)
                return notify_fail("��������ׯ�۵��������ƽ���ʿ�ǲ�������ġ�\n");
        if( me->is_fighting() )
                return notify_fail("�����ڴ���أ�\n");
        if( me->is_busy() )
                return notify_fail("������æ�أ�\n");
                
        if((int)me->query("mana") < 600 )
                return notify_fail("��ķ���������\n");
        if((int)me->query("sen") < 30 )
                return notify_fail("���޷����о�����\n");
        write("��Ҫץ˭��");        
        input_to( (: call_other, __FILE__, "select_other", me:));
        return 5+random(2);        
}

void select_other(object me,string arg)
{ 
        string msg;
        int ap, dp,success;
        object target;
        
        if(!arg||arg=="")return;        
                
       msg = HIC
        "$N�������˾����ģ�������һָ���ƽ���ʿ���ڣ�\n" 
        NOR;
        
        message_vision(msg, me);        
    if(!objectp(target = find_living(arg))||!environment(target)){
            tell_room(environment(me),"������ֳ�һ���ɫ�Ʋʣ�һ���ƽ���ʿ�����������������Ҳ�������ˣ�\n");
            return;
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

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared max_mana.

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.

      if(success == 1 ){
          tell_room(environment(target),"�������һֻ���ֽ�"+target->query("name")+"ץ���ˡ�\n");       
          target->move(environment(me));
          msg =  HIR "��һ�������ɫ�Ʋʶ��֣��ƽ���ʿ��$n������һ�ӣ���$nˤ�˸�ͷ������\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(10+random(5));
      }       
      else {
      msg =  HIR "��һ�������մ����ƽ���ʿ��У��뷨��������޷�ץ��$n��\n" NOR;
         message_vision(msg,me,target);         
         me->start_busy(1);
      } 
}

