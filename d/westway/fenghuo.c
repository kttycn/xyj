// create by snowcat.c 4/8/1997
// room: /d/westway/fenghuo.c

inherit ROOM;
#include <ansi.h>


void create ()
{
  set ("short", "���̨");
  set ("long", @LONG

�߸ߵķ��̨���ӷ��̨������ȥ��һƬãã����һ���
��ã��ʲôҲ�����塣����ȥ��ԶԶ�ط��̨һ����һ��
����Ⱥɽ����һֱͨ����߼�Զ����

LONG);

  set("exits", ([
        "northdown"  : __DIR__"jiayu",
      ]));
  set("outdoors", "changan-west");

  setup();
}


