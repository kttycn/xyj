inherit ROOM;
void create()
{
	set("short", "操场");
	set("long", @LONG
这是凤凰星军校的操场。在这里有很多学生在教官的督促下训练。右面是
学生的宿舍，左面是教学楼．
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"xiaoxue",
		"south" : __DIR__"wuchang",
		"west" : __DIR__"jiaoxue",
		"east" : __DIR__"shushe",
	]));
	set("objects", ([
		"/d/fenghuang/npc/kaoguan" : 1,
		"/d/fenghuang/npc/zhuren" : 1,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

