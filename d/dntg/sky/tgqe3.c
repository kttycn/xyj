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
"south"   : __DIR__"tgqe2",
"north"   : __DIR__"tgqe4",
]));


set("objects", ([
    __DIR__"npc/tianding1" : 1,
]));



set("outdoors", "sky");
setup();
}