// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "钟楼六层");
	set("long", @LONG
这里光线明亮，再往上的房间只有一层，四周无障，楼梯孤立。向上可
隐隐看到有一口大钟。
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"zhonglou5",
		"up" : __DIR__"zhonglou7",
	]));
	setup();
	replace_program(ROOM);
}
