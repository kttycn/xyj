inherit ROOM;
#include <ansi.h>
void create()
{
         set("short",HIM"�������"NOR);
         set("long",@LONG
�����������ȵ������ˣ����ܶ��������������㿴����������·��
����������������Ϲ���ţ���ʱ�������һЩ���˿־�Ĺ���������
��С��Ϊ�
LONG);
       set("objects",([
                   __DIR__"npc/juniao" : 2,
                     ]));
        set("exits",([
                  "west" : __DIR__"shangu2",
                  "north" : __DIR__"shangu2",
                  "south" : __DIR__"shangu2",
                  "east" : __DIR__"shangu2",
                  "southeast" : __DIR__"shangu2",
                  "southwest" : __DIR__"shangu2",
                  "northwest" : __DIR__"shangu2",
                  "northeast" : __DIR__"shangu3",
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

 if (!arg || arg != "up")
  return notify_fail("��Ҫ���Ķ�����\n");

  me ->move("/d/fenghuang/fenghuang/shangu1");
  message_vision("$N˳��ɽ�µ��ͱ�������ȥ������ŨŨ������ʹ$N����Ϣ���ʮ��������\n",me,room);
  me ->set("neili",1);
  return 1;
}
