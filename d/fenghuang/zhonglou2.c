// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "钟楼二层");
	set("long", @LONG
已经逐渐习惯了在这样的光线下看东西，四周墙壁之上画满了壁
画，只是年久，难以看清了。
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou3",
		"down" : __DIR__"zhonglou",
	]));
	setup();
	replace_program(ROOM);
}
