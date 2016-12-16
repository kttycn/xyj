inherit ROOM;
void create()
{
	set("short", "士兵学校");
	set("long", @LONG
这是凤凰星开设的军校。在这里集合了14-18岁的男女青年过着集团式的
寄宿制学习生活。生活及学习的一切费用均由学校负担。14-18岁每年均有毕
业考试，合格便可毕业并根据能力决定以后的军衔。
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"shangjie2",
		"south" : __DIR__"guangchang",
		"east" : __DIR__"zhonglou",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

