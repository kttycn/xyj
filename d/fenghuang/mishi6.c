#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", 
"这里是宗主府地下的密室，四周密不透风，你只能借着墙上昏暗的灯
光来勉强分辨方向。墙是用整块的青石砌合起来的，接合的甚是完美，
你难以从中找出一丝缝隙。密室正中摆放着一个"HIY"金盆"NOR"(jinpen)，一个
邪气很重的人双手正浸在金盆中，满脸血红，原来这里是宗主的秘密练功室。\n");

	set("exits", ([
		"west" : __DIR__"mishi5",
		"out" : __DIR__"qianyuan",
		"down" : __DIR__"mishi7",
	]));

	set("objects", ([
		__DIR__"npc/chenxin" : 1,
	]));
	set("item_desc", ([
		"jinpen" : "这是一个用黄金作成的盆子，里面盛满了"HIR"血红色的液体。\n"NOR,
	]));
	setup();
	replace_program(ROOM);
}

