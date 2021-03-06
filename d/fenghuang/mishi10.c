#include <ansi.h>
inherit ROOM;

void init();
int do_open(string);
void reset();
void close(object);

void create()
{
	set("short", "密道");
	set("long",
"你的眼前是一条用汉白玉铺成的台阶，一直向下延伸，两边的墙壁都
是花岗岩，墙上隔十来步就有一盏油灯，使你能看清周围,墙角一扇大门(door)。
\n");
	set("exits", ([
		"south": __DIR__"mishi8",
	]));

	set("item_desc", ([
		"door" : "这是一扇破旧的大门\n",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_open","open");
}
int do_open(string arg)
{
	object me;
	me=this_player();

	if (!arg || (arg!="door" ) )
		return  notify_fail("你要开什么？\n");

	set_temp("lock",1);
	if( query_temp("lock") == 1 && !present("phoenix key", me) )
		return notify_fail("钥匙都没有，怎么开门？\n");
	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁开了。\n", me);
		set("exits/down", __DIR__"mishi11");
		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
    }
}
void close(object room)
{
	message("vision","一阵风吹过,大门关上了。\n", room);
	room->delete("exits/down");
}

void reset()
{
	::reset();
	delete_temp("lock");
}
