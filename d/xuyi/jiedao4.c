// 神话世界·西游记之（世纪）
 
// create by jing 2000.7.13

inherit ROOM;

void create ()
{
	set ("short", "街道");
	set ("long", @LONG

太和街从蠙城中心广场直达东门外，延伸三里，是城内主要街道。街面是
由碗口大的彩色石块铺成，青兰紫绿，煞是好看。街道北面挑出一面旗子，
上写一个大大的“当”字。南面是一座高大的竹楼。
LONG);

	set("exits", ([
		"east"   : __DIR__"dongmen",
		"west"   : __DIR__"center",
		"south"   : __DIR__"feiyue",
		"north"   : __DIR__"dangpu",
	]));
	set("objects", ([
//        __DIR__"npc/people"   : 1,
	]));
	set("outdoors", __DIR__);

	setup();
}

