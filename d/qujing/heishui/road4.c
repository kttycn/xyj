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
  "north" : __DIR__"road3",
  "southwest" : __DIR__"hean5",
]));

        set("outdoors", "heishui");

  setup();
}


