//stone 20020613
// /d/guzhanchang/tandi7.c

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
        "west":   __DIR__"tandi10",
        "northeast":   __DIR__"tandi6",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        ]));
  setup();
}
