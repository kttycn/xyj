// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "钟楼三层");
	set("long", @LONG
到了这里，光线有所好转，因为四周墙壁之上都开了个小小窗户，和前
两层大不相同，墙上壁画早已脱落，几个工匠正在重新绘制，看来都是
丹青妙手。
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou4",
		"down" : __DIR__"zhonglou2",
	]));
	setup();
	replace_program(ROOM);
}
