//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
	set ("short","山门");
	set ("long", @LONG
这里是蜀山剑派的山门，整个山门前由大块的青石铺成，极为
平坦。但因年代久远，都有些破损。丛丛小草从石板的缝隙中长
了出来。广场周围都是密密的松树林，四角上各放了几块石碑，
字迹都甚为模糊。正前方黄墙碧瓦，飞檐翘檩，正中一道二丈来
宽，三丈来高的朱红杉木包铜大门(door)。上方一块大匾，龙飞
凤舞地书着『[1;36m 蜀 山 剑 派 [2;37;0m』四个大字。
LONG);

	set("outdoors", "shushan");
	set("exits", ([   
		"enter" : __DIR__"yongdao",
		"southdown" : __DIR__"yingketing",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/songer" : 1,
	]));

	create_door("enter", "大门", "out", DOOR_CLOSED);
	setup();
}

