#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","圆月小门");
	set("long",
"这是一个用大理石砌成的圆月形的小门，旁边竖着一块
木牌，上面写着："HIR"闲杂人等，禁止入内。\n"NOR);
	set("objects", ([
		__DIR__"npc/lanren": 1,
	]));
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"south"  : __DIR__"zoulang",
		"north"  : __DIR__"xiaodao",
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

