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
  "northwest" : __DIR__"road2",
  "south" : __DIR__"road4",
]));

        set("outdoors", "heishui");

  setup();
}


