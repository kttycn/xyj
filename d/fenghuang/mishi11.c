inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这里是宗主府地下的密室，四周密不透风，你只能借着墙上昏暗的灯
光来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，
你难以从中找出一丝缝隙。墙上好象雕有一些花纹。
LONG
	);
	set("objects", ([
//		__DIR__"npc/zchenxin" : 1,
		__DIR__"npc/fenghuang" : 1,
	]));
	set("exits", ([
		"up" : __DIR__"mishi6",
	]));

	setup();
	replace_program(ROOM);
}

