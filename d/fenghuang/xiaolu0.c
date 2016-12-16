#include <ansi.h>
inherit ROOM;

int do_go();

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条小路，不知通向什么地方，你一直走下去，
或许会有意想不到的发现。
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"xiaolu",
		"north"  : __DIR__"huayuan2",
	]));
	set("no_fly",1);
	setup();
}

void init()
{
	add_action("do_go","go");
}

int do_go()
{
	if(random(30)){
		this_player()->move(this_object());
		return 1;
	}
}
