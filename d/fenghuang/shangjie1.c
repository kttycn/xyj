inherit ROOM;
void create()
{
	set("short", "商业街");
	set("long", @LONG
你走在商业街上，踩着坚实的地面。东边是城中心，可以
听到生意人的吆喝声。西面是一条繁华的街道，那边十分吵闹。
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"west"  : __DIR__"shangjie2",
		"north" : __DIR__"wuqipu",
		"south" : __DIR__"zhahuopu",
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

