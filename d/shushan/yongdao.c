//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short","��");
  set ("long", @LONG

������������ǽ�����ɽ�����ˣ����������������䳡��
����ǰ�߾������ʵ��ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
"north" : __DIR__"sanhuang",
  "out" : __DIR__"shanmen",
 "east" : __DIR__"e-lianwu",
 "west" : __DIR__"w-lianwu",
  ]));
create_door("out", "ʯ��", "enter", DOOR_CLOSED);
setup();
}
