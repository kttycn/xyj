//u/stone/d/balcony.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","露天阳台");
	set ("long", @LONG
	
一个宽宽的阳台，站在这里你不禁深深的呼了几口气，伸了个懒
腰，顿时感到神清气爽，一眼望下去，一大片青青的草地映入眼
帘。
南面是二楼。
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"south" : "/d/update/stone/d/sfloor",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	setup();
}