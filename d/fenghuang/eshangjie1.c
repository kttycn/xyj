inherit ROOM;
void create()
{
	set("short", "商业街");
	set("long", @LONG
你走在商业街上，踩着坚实的地面。西面是城中心，这里可以
听到生意人的吆喝声。这里是一条繁华的街道，北面是凤凰大
银号，南面是一家夜总会，空港的船员经常到那里去寻欢作乐！
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"eshangjie2",
		"west"  : __DIR__"zhongxin",
		"north" : __DIR__"bank",
		"south" : __DIR__"playroom",
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

