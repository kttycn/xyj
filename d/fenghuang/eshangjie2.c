inherit ROOM;
void create()
{
	set("short", "商业街");
	set("long", @LONG
你走在商业街上，踩着坚实的地面。这里可以听到生意人的吆喝
声。这里是一条繁华的街道，北面是龙升典当行，南面是凤凰星
最豪华的酒店，过往的旅客都到那里去休息！
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"rukou",
		"west"  : __DIR__"eshangjie1",
		"north" : __DIR__"dangpu",
		"south" : __DIR__"sleep-room",
	]));
	set("objects", ([
//          "/d/city/npc/?" : 1,
//          "/d/city/npc/?"    : 2,
	]));
//      set("no_clean_up", 0);
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


