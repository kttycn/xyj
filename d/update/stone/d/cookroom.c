//u/stone/d/cookroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","厨房");
	set ("long", @LONG
	
这是巫师石头的料理厨房，各种炊具一应具全，可以在这里做各
种种类的菜肴、点心、小吃、烧烤。东墙角有一个大大的电冰箱，
（icebox)，西墙角面立着一台自动售货机（automat)。
西南面是石头的工作室。
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
		"southwest" : "/d/update/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	set("objects", ([ /* sizeof() == 2 */
//		__DIR__"npc/robot1" : 1,
		"/d/update/stone/obj/automat" : 1,
        ]));
	setup();
}