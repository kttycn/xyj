//u/stone/d/jianshenfang.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","石头的健身房");
	set ("long", @LONG
	
这是巫师石头的健身房，大大的房间中放着一台台，各式各样的
健身器械，地上铺着厚厚的地毯，顶灯柔合的放着光，东墙角上
有一台立式的饮水机。石头有时候到这来健身。
东面是石头的工作室。
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"northeast" : __DIR__"chufang",
//		"up": "__DIR__guestroom",
		"east": "/d/update/stone/d/stoneroom",
	]));
	setup();
}