#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","走廊");
	set("long",@LONG
这是一条用汉白玉石筑成的走廊，地上铺着红色的地毯，两边站着
几个美丽的女孩子，正笑盈盈的看着你。你不禁放慢了脚步。
LONG);
	set("objects", ([
		__DIR__"npc/shinv": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"huayuan1",
		"north"  : __DIR__"zoulang3",
	]));
	setup();
	replace_program(ROOM);
}

