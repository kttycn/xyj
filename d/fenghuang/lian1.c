inherit ROOM;
void create()
{  
	set("short", "模拟实战室");
	set("long", @LONG
这里是军校学生训练的地方。有几个练功用机器人摆在那里，有几个弟子手持
兵器与练功人互相拆招。
LONG );
	set("objects", ([
		__DIR__"obj/jqr1" : 1,         
	]));
	set("exits", ([
		"north" : __DIR__"wuchang",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

