//Cracked by Roath
// Room: /d/nanhai/road1
inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG
 
����һ��ͨ����ɽ��С·��
LONG);

  set("outdoors", "putuo");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "southup" : __DIR__"road1",
]));

  setup();
}
