// create by snowcat.c 4/8/1997
// room: /d/westway/dadao.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","���");
  set ("long", @LONG

����һ�������Ĵ������ԶԶ��ɽ�����ƹ�����ز�ã������
������ش��ţ�����·������ķ�ɳ��������������Ե����ˣ�
���ڴҴ�ææ�ظ���·�������ǽ�ǿ����������ٸ�һ��·��
���Ե��������ˡ�

LONG);

  set("exits", ([
        "east" : __DIR__"jincheng",
        "west" : __DIR__"yongjing",
      ]));
   set("objects",([
 //  "/d/qujing/kusong/npc/jiruhuo" : 1,
   ]));
  set("outdoors", "changan-west");

  setup();
}



