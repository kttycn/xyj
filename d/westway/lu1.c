inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short","ɽ����");
  set ("long", @LONG

ɽ����ں����ġ��ϱߵĶ��ſڶ��ź�Щ�Ӳݣ���Ŵ������
�������ġ�����ɽ�������ͨ�����
LONG);

  set("exits", ([
        "south" : __DIR__"shizhan",
        "north"      : __DIR__"lu2",
      ]));
//  set("outdoors", "changan-west");
        set("objects", 
        ([ //sizeof() == 1
                "/d/westway/obj/tielong" : 1,
        ]));

  setup();
}





