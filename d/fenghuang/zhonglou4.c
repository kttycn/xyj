// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "钟楼四层");
	set("long", @LONG
这里四周密密严严，丝缝不露，
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou5",
		"down" : __DIR__"zhonglou3",
	]));
	setup();
	replace_program(ROOM);
}
