inherit ROOM;
void create()
{
             set("short","一望无际的大草原");
             set("long",@LONG
这里是一片一望无际的大草原，两旁都是一米多高的草，遮挡着
你的视线，让你分不清东南西北。但冥冥之中有似乎有一鼓力量
指使着你继续向前。
LONG);
         set("exits",([
                 "east" : __DIR__"shangu1",
                 "south" : __DIR__"pingyuan5",
                 "north" : __DIR__"pingyuan4",
                 "west" : __DIR__"pingyuan5",
                       ]));
  setup();
}
