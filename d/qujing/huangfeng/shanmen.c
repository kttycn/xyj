// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/shanmen.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG

С·��ͷ���������ţ���������һ���Ҷ���顰������Ժ��
�ĸ�������֡��ſ����������ˣ���������һ�빪������

LONG);

  set("exits", ([
        "southdown"    : __DIR__"yangchanglu6",
        "north"        : __DIR__"chanyuan",
      ]));
  set("objects", ([
       __DIR__"npc/ykmonk":2
      ]));
  set("outdoors", __DIR__);
  setup();

}
