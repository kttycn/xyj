//u/stone/d/sfloor.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","二楼");
	set ("long", @LONG

顺着大理石的台阶，走上二楼。
东面是招待男士客人小住的客房，南面是招待女士客人小住的客房。
西面是一间会议室，北面是一个露天的阳台。楼上是一个大花园。

楼下是石头的工作室。
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"east" : "/d/update/stone/d/guestroom",
		"west" : "/d/update/stone/d/boardroom",
		"north" : "/d/update/stone/d/balcony",
		"south" : "/d/update/stone/d/guestroom1",
		"up": "/d/update/stone/d/garden",
		"down": "/d/update/stone/d/stoneroom",
	]));
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	setup();
}