//edit by lucas
inherit ROOM;

void create ()
{
  set ("short", "���ŷ�");
  set ("long", @LONG 
�������������������ŷ�����������Ʈ�����������ˮֱ����
���ԡ���ɽ��ɽ����ˮ��ˮ�����ѵ���һ�����������ܲ���
������һ����ζ�أ�
LONG);

  set("exits", ([
        "east"   : __DIR__"zoulang5",
      ]));
  set("objects", ([
        __DIR__"obj/fish" : 1,
        __DIR__"obj/xierou" : 1, 
        __DIR__"obj/xiaren" : 1,
        __DIR__"obj/baoyu" : 1,
      ]));

  setup();
}

