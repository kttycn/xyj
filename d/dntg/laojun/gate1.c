//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "���ʹ�����");
set("long", @LONG
    
�������̫���Ͼ���ס���������ʹ��ˡ�
�ⶵ�ʹ�����ʮ����֮�ϣ������и�·��
����������̫���Ͼ�����̸����
LONG );


set("exits", ([
  "west"   : "/d/dntg/yaochi/wmj4",
   "enter" : __DIR__"hall1",
]));


set("objects", ([
]));



set("outdoors", "sky");

setup();
}
