//u/stone/d/boardroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","������");
	set ("long", @LONG
	

ʯͷ����������һȺ���������о�MUD��̽��BUG���д��̼��ɡ�
��������ʯͷ�Ĺ����ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"east" : "/d/update/stone/d/sfloor",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "/d/update/stone/d/stoneroom",
	]));
	
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	
	setup();
}