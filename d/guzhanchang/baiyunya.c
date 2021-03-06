// stone 20020620
// /d/guzhanchang/baiyunya.c

inherit ROOM;
#include <room.h>
string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", "白云岩");
  set ("long", @LONG

一块半亩大小平坦的大岩石，不时有片片白云从脚下飘。
向四下望去，只见山势绵连，一望无涯，这一陡崖在五
里方圆内，最为突出。
LONG);
  set("exits", ([ /* sizeof() == 3 */
]));
  set("objects", ([
        __DIR__"npc/xianhe":1,
]));
	set("outdoors", 1);
  setup();
}

void init() {
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();
	
	if( !arg || (arg != "left" && arg != "right" && arg != "up" && arg != "down" ) ){
		return notify_fail("你要爬到哪里去？\n");
	}

	if( arg == "left" ) 
	{
		message_vision("$N紧贴岩壁，死抓石棱地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move("/d/wusheng/xuanya3");
	}

	else return notify_fail( "往"+direction_name(arg)+"已经没有着手之点了。\n" );

	message_vision("$N从"+direction_rev(arg)+"面爬了过来，轻轻吁出了一口气。\n", me);   
	return 1;    

}

string direction_name(string arg)
{
	if ( arg == "right" ) return "右";
	else if ( arg == "left" ) return "左";
	else if ( arg == "up" ) return "上";
	else if ( arg == "down" ) return "下";
	else return "不知道哪儿";
}

string direction_rev(string arg)
{
	if ( arg == "right" ) return "左";
	else if ( arg == "left" ) return "右";
	else if ( arg == "up" ) return "下";
	else if ( arg == "down" ) return "上";
	else return "不知道哪儿";
}