//stone 20020613
// /d/guzhanchang/tandi11.c

inherit ROOM;
#include <tandi.h>

void create ()
{
  set ("short", "潭底");
  set ("long", @LONG

四周无数个旋涡无声的扑击着，又形成了一个巨大的旋涡，滑
向了河的深处，声势骇然，却寂静无声，你再也站不住了，如
风吹荷花，摇摆不定，随时都有可能被旋涡卷走。

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
