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
                 "south" : __DIR__"pingyuan3",
                 "north" : __DIR__"pingyuan3",
                 "west" : __DIR__"pingyuan2",
                 "east" : __DIR__"pingyuan4",
                       ]));
  setup();
}
