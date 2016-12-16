inherit ROOM;
#include <ansi.h>
void create()
{
         set("short",HIM"雾灵谷内"NOR);
         set("long",@LONG
这里就是雾灵谷的里面了，四周都弥漫着烟雾，让你看不清哪里是路，
哪里是雾。你在雾中瞎串着，不时都会出现一些令人恐惧的怪兽来，还
是小心为妙。
LONG);
       set("objects",([
                   __DIR__"npc/juniao" : 2,
                     ]));
        set("exits",([
                  "west" : __DIR__"shangu2",
                  "north" : __DIR__"shangu2",
                  "south" : __DIR__"shangu2",
                  "east" : __DIR__"shangu2",
                  "southeast" : __DIR__"shangu2",
                  "southwest" : __DIR__"shangu2",
                  "northwest" : __DIR__"shangu2",
                  "northeast" : __DIR__"shangu3",
                    ]));
      setup();
}
void init()
{
  add_action("do_climb","climb");
}
int do_climb(string arg)
{
     object room;
      object me;
     me = this_player();

 if (!arg || arg != "up")
  return notify_fail("你要往哪儿爬？\n");

  me ->move("/d/fenghuang/fenghuang/shangu1");
  message_vision("$N顺着山崖的峭壁爬了上去，但是浓浓的雾气使$N的气息变得十分虚弱。\n",me,room);
  me ->set("neili",1);
  return 1;
}
