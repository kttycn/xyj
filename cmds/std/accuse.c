//Cracked by Roath
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
     //accuse.c
//Feb/01/97 wuliao@xyj
#include <login.h>
#include <ansi.h>

int main(object me, string arg){

        object obj;
        int year, times;
        string pro;

   seteuid(getuid());

   if( me->query("combat_exp")<10000 )
       return notify_fail("�ú������ɣ�������ż�ٱ��ˣ� \n");
        if( !arg )
       return notify_fail("������˭�� \n");
        obj = find_player(arg);
        if ( !obj )
            return notify_fail("����˶��������ϣ� \n");
        if( wizardp(obj) )
       return notify_fail("�㲻�ܼ����ʦ��\n");
        times = me->query("robot_accusing");
   if( obj==me ){
       tell_object(me, "���Ѿ�����˱���" + chinese_number(times) + "�Ρ�\n");
            return 1;
//       return notify_fail("��Ҫ����Լ��� \n");
        }
        pro = gender_pronoun(obj->query("gender"));
   if( obj->is_ghost() )
            return notify_fail( obj->name(1) + "�Ѿ����ˣ���" + pro + "һ��ɡ�\n");
   if( environment(obj)->query("short")=="��Ժ" )
       return notify_fail( obj->name(1) + "�Ѿ���ץ����Ժ�ˣ� \n");
        if( !wizardp(me) ){
            year = me->query("combat_exp")/1000;
            if( 2*times>(year + 2 ))
                return notify_fail("���Ѿ���ʱ��ʧȥ�˼��Ȩ�� \n");
            me->add("robot_accusing",1);
       if( 2*(me->query("robot_accusing"))>( year + 2) ){
                me->move("/d/wiz/gongtang"); 
     return notify_fail("�����ü��Ȩ�����������Ұɣ��� \n");
             }
        else{
                  if( obj->query_temp("accuser/"+getuid(me)) ){
                       return notify_fail("���Ѿ��ڼ��" + pro + "�ˣ�� \n");
                  }
                  obj->set_temp("accuser/"+getuid(me), me->name() );
                  if( sizeof(obj->query_temp("accuser"))>4 ){
                  ROBOT_CHECK->test_me(obj);
                  tell_object(obj, HIW+"�㱻�˼���ˣ��������һ��СС�Ĳ��顣\n" NOR);     
       tell_object(me, HIW+"��Ͷ�����һƱ��" + obj->name() + "��ץ���˷�Ժ�� \n" NOR);
                  obj->start_busy(20);
                  obj->delete_temp("accuser");
                  if( present("judge", environment(obj)))
                  me->command("chat* hehe " + obj->query("id"));
                  }
                  else{
                  tell_object(me, HIW+"����" + obj->name() + "�����ˣ�����" + chinese_number( 5 - sizeof(obj->query_temp("accuser")) ) + "Ʊ�� \n" NOR);
                  }
              me->start_busy(1);
              }
        }
   else{
            ROBOT_CHECK->test_me(obj);
            tell_object(obj, HIW+"�㱻�˼���ˣ��������һ��СС�Ĳ��顣\n" NOR);
            obj->start_busy(20);
            obj->delete_temp("accuser");
            present("judge",environment(obj))->command("chat* hehe "+obj->query("id")); 
   }
      return 1;
} 

int help(object me)
{
write(@HELP
ָ���ʽ : accuse <ĳ��>

���ָ��������ٱ��˻����ˣ�����Ҫ��ʮ��ĵ��С������ʹ�����
һָ�����ܴ������ɳ�������������һ�롣�����߽�����Ϊ����
���ң����빫�ã�����

accuse �Լ���    �������ٱ����ܴ�����
accuse ���ˣ�    ��ٱ��ˡ�

HELP
);
   return 1;
} 
