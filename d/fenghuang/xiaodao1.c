#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "小道");
	set("long", @LONG
这里平时人迹罕至，杂草丛生，满目荒凉，杂草中星星
点点的散落着一些白色东西，你仔细一看，竟然是一些
尸骨残骸。你不禁心底升起一股寒气，打了个寒战。
LONG);
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"xiaodao",
		"north"  : __DIR__"xiaodao2"
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

