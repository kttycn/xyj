// changan wusheng
// xuanya3.c

inherit ROOM;
#include <room.h>

string direction_name(string);
string direction_rev(string);

void create ()
{
  set ("short", "圣火断崖上");
  set ("long", @LONG

圣火断崖风光秀丽，当真是好去处！前方一个山洞，洞里有祥
云绕绕，隐有红光。崖壁上多是青苔锈葛，看上去异常的滑手。
崖上有兽鸣阵阵，空山回音不绝。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huoyunwai",
  "down" : __DIR__"xuanya2",
]));
	set("outdoors", "wusheng");
  setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me;

	me=this_player();
	

	if( !arg || (arg != "left" && arg != "right" && arg != "up" ) ){
		return notify_fail("你要爬到哪里去？\n");
	}

	if( arg == "left" ) 
	{
		message_vision("$N紧贴岩壁，死抓石棱地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move("/d/guzhanchang/wangxianya");
	}
	
	else if( arg == "right" ) 
	{
		message_vision("$N紧贴岩壁，死抓石棱地往"+direction_name(arg)+"爬了过去。\n", me);
		me->move("/d/guzhanchang/baiyunya");
	}

	else return notify_fail( "往"+direction_name(arg)+"已经没有着手之点了。\n" );

	message_vision("$N从"+direction_rev(arg)+"面爬了过来，轻轻吁出了一口气。\n", me);   
	return 1;    
  
}

string direction_name(string arg)
{
	if ( arg == "left" ) return "左";
	else if ( arg == "right" ) return "右";
	else if ( arg == "up" ) return "上";
	else return "不知道哪儿";
}

string direction_rev(string arg)
{
	if ( arg == "left" ) return "右";
	else if ( arg == "right" ) return "左";
	else if ( arg == "up" ) return "下";
	else return "不知道哪儿";
}