inherit ROOM;
#include <ansi.h>
void create()
{
               set("short",HIB"雾灵谷内"NOR);
               set("long",@LONG
    这里就是雾灵谷的里面了，四周都弥漫着烟雾，让你看不清哪里是路，
哪里是雾。你在雾中瞎串着，不时都会出现一些令人恐惧的怪兽来，还
是小心为妙。
LONG);

               set("exits",([
                  "north" : __DIR__"shangu3",
                  "south" : __DIR__"shangu3",
                  "east" : __DIR__"shangu4",
                  "west" : __DIR__"shangu3",
                  "southwest" : __DIR__"shangu2",
                  "northwest" : __DIR__"shangu3",
                  "northeast" : __DIR__"shangu3",
                  "southeast" : __DIR__"shangu3",
                  ]));
            set("objects",([
            __DIR__"npc/juniao" : 4,
                             ]));
   setup();
}
