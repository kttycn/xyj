inherit ROOM;

void create ()
{
  set ("short", "ɽ��");
  set ("long", @LONG
������һƬ������ɽ��������é�ݴ�������ľïʢ����������
�ĵģ�������һ�����޵�������Զ��������������ˮ�죬����
��һ����Ӱɡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road2",
  "north" : "/d/qujing/chechi/shatan1",
]));

        set("outdoors", "heishui");

  setup();
}


