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
  "north" : __DIR__"road1",
  "southeast" : __DIR__"road3",
]));

        set("outdoors", "heishui");

  setup();
}


