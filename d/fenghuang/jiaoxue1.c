inherit ROOM;
void create()
{
	set("short", "教学楼二楼");
	set("long", @LONG
这里是凤凰军校的教学大楼，里面是学员学习的地方．
LONG );
	set("exits", ([
		"down" : __DIR__"jiaoxue",
	]));
	set("objects", ([
		__DIR__"npc/master2" : 1,         
	]));
	setup();
	replace_program(ROOM);
}

