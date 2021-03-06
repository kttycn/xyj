// Room: /d/liwu/happyjie.c

inherit ROOM;

void create()
{
	set("short", "欢乐街");
	set("long", @LONG
你走在一条拥挤的街道上，这里简直是欢乐的海洋，许多人在街上唱歌、跳
舞，西南方有一个热闹的广场。东北边是一幢漂亮的红白房子，里面正在欢庆节
日。东南边是一条宠物街，西北边是一幢豪华别墅，可以看到里面正在开晚会，
好不热闹。
LONG	);
	set("outdoors", "city");


	set("chat_room",1);
	set("exits", ([
		"northeast" : __DIR__"lipinroom",
        "southeast" : __DIR__"dogjie",
		"southwest" : "/d/city/center",
		"up" : __DIR__"spirit",
		"northwest" : __DIR__"partyroom",
	]));

	set("objects", ([
		__DIR__"npc/happyboy" : 1,
		__DIR__"npc/happygirl" : 1,
		__DIR__"npc/shaofu" : 1,
		__DIR__"npc/jentleman" : 1,
	]));
	set("freeze",1);

	setup();
	replace_program(ROOM);
	call_other("/d/city/liwu/obj/bboard", "???");
}

