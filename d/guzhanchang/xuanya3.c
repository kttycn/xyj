// changan wusheng
// xuanya3.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���ƶ�����");
  set ("long", @LONG

���ƶ��·�������������Ǻ�ȥ����ǰ��һ��ɽ������������
�����ƣ����к�⡣�±��϶�����̦��𣬿���ȥ�쳣�Ļ��֡�
�������������󣬿�ɽ����������
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huoyunwai",
  "down" : __DIR__"xuanya2",
]));
	set("outdoors", 1);
  setup();
}

