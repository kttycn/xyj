inherit ROOM;
void create()
{
	set("short", "模拟实战室入口");
	set("long", @LONG
这里是凤凰军校的模拟实战室的入口，里面是一个高科技的模拟
实战室．
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"lian1",
	]));
	set("objects", ([
		__DIR__"npc/master3" : 1,         
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


