inherit ROOM;
void create()
{
	set("short", "教学楼");
	set("long", @LONG
这里是凤凰军校的教学大楼，里面是学员学习的地方．
LONG );
	set("exits", ([
		"west" : __DIR__"shitang",
		"east" : __DIR__"guangchang",
		"up" : __DIR__"jiaoxue1",
	]));
	set("objects", ([
		__DIR__"npc/master1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
