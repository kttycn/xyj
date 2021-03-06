//stone 20020613
//  /d/guzhanchang/tandi1.c

inherit ROOM;
#include <tandi.h>

void create ()
{
  set ("short", "潭底");
  set ("long", @LONG

四周也布满了参差不齐的岩石，岩石间丛生着乱发一般的水草，
水草在水中飘散，宛如发丝似的。小草间滑动着许多道不出名
的怪鱼。这些鱼不但形状不一，有的体如尖椎，有的形如短棍，
有的肩如圆饼，颜色更是七彩纷呈，光怪陆离。岩石之间，还
散布着一些刀剑兵刃和死人的白骨！

LONG);
  set("exits", ([
        "south"  : __DIR__"tandi2",
        "north":   __DIR__"tandi3",
        "up":   __DIR__"shuitan",
        ]));
  set("objects",([
        "/d/jz/obj/fish2" : 2,
        __DIR__"obj/goldstone" : 1,
        __DIR__"obj/skull" : 1,
        "/d/obj/weapon/sword/tiejian" : 1,
        ]));
  setup();
}
