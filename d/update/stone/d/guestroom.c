//u/stone/d/guestroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","男士客房");
	set ("long", @LONG

这是一间用来招待客人的豪华客户，装饰得富丽堂皇，极富有
现代气息，各种用具，一应具备。据说是按总统的标准建的。

西面是二楼。
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : "u/stone/d/guestroom",
		"west" : "/d/update/stone/d/sfloor",
//		"north" : "u/stone/balcony",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"down": "u/stone/d/stoneroom",
	]));
	setup();
}