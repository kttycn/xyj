// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "���й·�");
  set ("long", @LONG

�·��ں���Ư���������ǰ�ãã��һƬ����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"aolaiws.c",
]));
set("zuo_trigger", 0);
  set("outdoors", "changan-south");

  setup();
}