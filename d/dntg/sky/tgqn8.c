//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "�칬��ǽ");
set("long", @LONG
    
�ߴ���ΰ���칬��ǽ���������������ߣ�����
��ǽ��ȥ������һ�ڣ��岽һ�ڡ��䱸ɭ�ϡ�
LONG );


set("exits", ([
  "south"   : __DIR__"tgqe8",
  "west"   : __DIR__"tgqn7",
]));


set("objects", ([
    __DIR__"npc/autumn-gongcao" : 1,
]));



set("outdoors", "sky");

setup();
}