#include <ansi.h>

#include <room.h>
inherit ROOM;

void create()
{
set("short", HBRED HIY" �� �� �� �� "NOR);
set("long", @LONG
    
LONG );


set("exits", ([
  "south"   : __DIR__"qianyuangong",
]));


set("objects", ([
  __DIR__"npc/yuhuang"   : 1,
  __DIR__"npc/wuquxingjun"   : 1,
]));

setup();
}
