//����ɽ�ɡ�mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
int do_dive();
void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

������һ��С��ˮ̶�����������ϵ��ٲ���������ˮ�������µ�����
��ȥ��������ˮ̶�ɣ�������Ŀ��˿����ܣ�ȫ���������ͱڣ���
�����ȥ�������ˣ�ֻ�������漣������
LONG);

  set("exits", ([      
         "south" : __DIR__"shanjian",
 ]));
 setup();
}
void init()
{
    add_action("do_dive", "dive");
}
int do_dive()
{   
   object me, zhou;
   object ridee;
   me=this_player();
   ridee=me->ride();
   if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="��")
		&& (string)me->query("family/family_name")!="����"
		&& (string)me->query("family/family_name")!="��������")
                           return notify_fail("��һ����������ˮ�����\n"+
		  "\n��û�����ͱ���ð�����ֻ�øϽ����ϰ�����\n");

  if (ridee && ridee->query("under_water")) {
  message_vision(HIY"$Nһ��$n��ͷ�����˴���Ծ��ˮ�С�\n"NOR,me,ridee);
  ridee->move(__DIR__"midao");
  }
  else  message_vision(HIY "$Nһ����������ˮ�У�Ȼ�󲻼��ˣ�\n" NOR, me);
  me->move(__DIR__"midao");
  message_vision(HIW"$N����ˮ���ĳ����֪������������һ���ط���\n"NOR,me);
  message_vision(HIR"$N��ͷͻȻһ������,��ʱʧȥ��֪����\n"NOR,me);
  me->unconcious();
  return 1;
}

