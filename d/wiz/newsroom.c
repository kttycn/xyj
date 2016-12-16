// Room: /d/wiz/newsroom at fei
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", MAG"月影奇缘"NOR"新闻发布中心");
	set ("long", @LONG

　　这里是月影奇缘的新闻发布中心，有什么新闻都可以在这里发
布，然后系统自动通知所有玩家。

LONG);

	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"wizroom",
	]));
	set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}
