//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "������");
set("long", @LONG
    
���������칬���ر����أ�������ֱͨ�칬��Ӫ��
����פ���ż�ʮ���������Ӫ�Ա�������������
�����䡣
LONG );


set("exits", ([
  "north"   : "/d/dntg/sky/yunluw3",
  "south"   : __DIR__"hgj2",
]));


set("objects", ([
]));



set("outdoors", "sky");

setup();
}