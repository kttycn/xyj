inherit ROOM;
void create()
{
	set("short", "商业街");
	set("long", @LONG
这里是凤凰城的商业街。由于这是凤凰星中心城市，可以十分繁华。
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"shangjie1",
		"north" : __DIR__"jqrdian",
		"down" : __DIR__"shanghui",
		"south" : __DIR__"xiaoxue",
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

