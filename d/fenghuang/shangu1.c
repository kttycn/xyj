inherit ROOM;
#include <ansi.h>
void create()
{
         set("short",HIR"�����"NOR);
         set("long",@LONG
������Ƿ�����������˿ֲ��ĵط�--����ȣ������������ʺϹ���
���棬���������������ۼ�����������ָ����Ĺ��ޣ���̬���죬
�����˿ֲ�������������ȵ�����ʮ�����⣬�������������Ĺ���
��ͷ��������Ұ����޵���������������һ�����ǲ���������ģ�����
��˵Ĵ�ͳ��ҲҪ�������֡�
LONG);
        set("exits",([
                  "west" : __DIR__"pingyuan5",
                    ]));
      setup();
}
void init()
{
  add_action("do_climb","climb");
}
int do_climb(string arg)
{
     object room;
      object me;
     me = this_player();

   if (me->query("combat_exp") < 300000)
  return notify_fail("������㱾��Ҳ�������ȣ����ǻ�ȥ������ɣ�С��Ҫ��Ŷ��\n");
 if (!arg || arg != "down")
  return notify_fail("��Ҫ���Ķ�����\n");
  if (!(me->query_temp("������")))
  return notify_fail("��û��������棿\n");

  me ->move("/d/fenghuang/fenghuang/shangu2");
  message_vision("$N˳��ɽ�µ��ͱ���������������ŨŨ������ʹ$N����Ϣ���ʮ��������\n",me,room);
  me ->set("neili",1);
  return 1;
}
