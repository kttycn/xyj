// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37m������[2;37;0m");
  set ("long", @LONG

��Լ�����ֳ�һ����ɫ��¥������̫������������������������
�޿�������ж�ǰ������Ϊһ�����Źؾ��޷��ٻ������ˡ���Χ��
�ߵ�Ұ�����ҡ�ڣ����з��������ķ�����
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"new-out2",
  "north" : __DIR__"new-out6",
  "west": __DIR__"new-out8",
  "east": __DIR__"new-out4",
]));
	set("no_fight", 1);
	set("no_magic",1);
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pang" : 1,
]));

  setup();
}
