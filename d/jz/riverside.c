//  妖神之争 １。０
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "岸边");
	set("long", @LONG
这是一处空旷的道路，旁边是水，两面是山，山青水秀，
树叶落得满地都是，鸟儿欢快的叫着，你不禁感到心情特别
的好。
LONG);
	set("exits",([
		"westup": __DIR__"shanlu1",
	]));
	set("outdoors", "jz");
	setup();
	replace_program(ROOM);
}
