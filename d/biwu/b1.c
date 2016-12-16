#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "风雨楼");
	set("long", @LONG
这是一个纠集了天上人间十三大高手的楼，共有十四层之高。
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"northdown" : "/d/city/center",
		"up":__DIR__"b2",
	]));
		set("objects", ([
			__DIR__"npc/qinqiong": 1,
		]));
	setup();
}

void init()
{
	add_action("do_dazuo","dazuo");
	add_action("do_dazuo","exercise");
	if(userp(this_player()) && (!this_player()->query_temp("for_okok")))
	{
		call_out("awayaway",900);
		message_vision("你只有一刻钟的时间来击败所有高手。无论成功与否，一刻钟后你将自动被送回长安十字街头。\n",this_player());
		this_player()->set_temp("for_okok",1);
	}
}

int awayaway()
{
	object me;
	me= this_player();
	message_vision("已过了一刻钟的时间，$N将被送到广场中央。\n",me);
	me->move("/d/city/center");
	message_vision("$N的身形突然出现在广场中央。\n",me);
	this_player()->set_temp("for_okok",0);
	return 1;
}

int do_dazuo()
{
	object me;
	me = this_player();
	tell_object(me,"这里不能打坐。\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object ob;
	if( userp(me) && dir=="up" && ob=present("qin qiong", this_object()))
		return notify_fail("你想硬闯？！\n");
	return 1;
}
