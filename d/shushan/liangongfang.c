//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","������");
  set ("long", @LONG

������ɽ����ƽʱ�����ĵط������������С��¯�������������ƣ�
�������������ɾ�һ�㡣
LONG);

  set("exits", ([ 
  "west" : __DIR__"eastway3",
  ]));
  set("objects", ([
        __DIR__"npc/qingyunzi" : 1,
  ]));
    setup();
}






