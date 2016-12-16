//u/stone/d/garden.c
//stone 2001/12/21

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","二楼");
	set ("long", @LONG

这是一个大花园。上面栽种各种奇花异草，幽幽的花香、青草的清
新、一群群的蜜蜂、蝴蝶在花丛中飞舞，好一幅美景！

楼下是石头的二楼。
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"down": "/d/update/stone/d/sfloor",
	]));
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	setup();
}