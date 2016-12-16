//u/stone/d/bookroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","石头的藏书房");
	set ("long", @LONG
	
这是巫师石头的藏书房，只见四周都是一排排及地而起的的大书架，
地上也是一堆堆的尚未整理放入书架的书籍、辞典、漫画、杂志。
西墙角上还靠着一架小梯子，东墙角有一张软榻，看起来非常柔软，
石头经常在这博览群书。墙上挂着一对对联（duilian)。

西面是石头的高级工作室。
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"northeast" : __DIR__"chufang",
//		"up": "__DIR__guestroom",
		"west": "/d/update/stone/d/stoneroom",
		
	]));
	 set("item_desc",([
                          "duilian" : HIR "
              明                古   
              灯                书
              常                常
              为		作
              伴		朋 \n\n\n "NOR,
              
        ]));
         set("objects", ([ 
		"/d/update/stone/obj/desk" : 1,  
	 ]));

	setup();
}

void init()


{
        add_action("do_push","knock");
 }

int do_push(string arg)
{
        object me = this_player();

        if( !arg || arg != "wall" )
                return notify_fail("你要敲什么？\n");

//        if( me->query("obstacle/hf") == "done" )
//                return notify_fail("你敲了半天的墙，也没有发现什么。\n");

        set("exits/south", "/d/update/stone/d/mishi");
        message_vision(HIC"$N轻轻往墙上一敲，忽然墙向一侧移动，这里竟然还有一个房间。\n"NOR,me);
        remove_call_out("close");
        call_out("close", 3, me);
        return 1;
}
void close()
{
        object room = load_object("/d/update/stone/d/bookroom");
        message("vision","忽然墙自动的合拢了。\n", room);
        room->delete("exits/south");
}
