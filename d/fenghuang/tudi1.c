inherit ROOM;
void create()
{
       set("short","小道");
       set("long",@LONG
这里是一条小路，不知道通往哪儿，小道两旁风呼呼的吹着，
似乎在暗示着什么。道路两旁的草越来越密集了，你隐隐约约
觉得有些不妥。
LONG)
;
            set("exits",([
                      "east" : __DIR__"tudi2",
                        ]));
     setup();
}
