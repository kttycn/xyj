// Room: /d/liwu/dogjie.c

inherit ROOM;

void create()
{
	set("short", "宠物街");
	set("long", @LONG
这是一条宽阔的青石街道，由于与欢乐节相连，所以街道上充满
了喜悦的气氛。西北边喧哗热闹，那就是欢乐街了，东边是一个不太
大的宠物寄养屋，你可以把你的宠物寄养在那里。
LONG
	);
	set("outdoors", "city");

	set("exits", ([
		"northwest" : __DIR__"happyjie",
              "east" : __DIR__"dog_room",
	]));

	set("objects", ([
		__DIR__"npc/shaofu" : 1,
		__DIR__"npc/jentleman" : 1,
		__DIR__"npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}

