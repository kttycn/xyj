//stone 20020613
// /d/guzhanchang/tandi11.c

inherit ROOM;
#include <tandi.h>

void create ()
{
  set ("short", "̶��");
  set ("long", @LONG

���������������������˻��ţ����γ���һ���޴�����У���
���˺ӵ�������ƺ�Ȼ��ȴ�ž�����������Ҳվ��ס�ˣ���
�紵�ɻ���ҡ�ڲ�������ʱ���п��ܱ����о��ߡ�

LONG);
  set("exits", ([
        "east":   __DIR__"tandi7",
        "northwest":   __DIR__"tandi11",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
