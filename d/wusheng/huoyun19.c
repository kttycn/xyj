// changan wusheng
// baiyu19.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "ʥ��");
  set ("long", @LONG

���ں�����������������ڶ��ڻص���˿˿��ζ�������Ρ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north": __DIR__"shijie9",
  "northeast": __DIR__"huoyun"+sprintf("%d",random(20)),
  "northwest": __DIR__"huoyun"+sprintf("%d",random(20)),
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}
