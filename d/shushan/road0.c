//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
void create ()
{
	set ("short","曲折小路");
	set ("long", @LONG

这是一条又长又窄的曲折小路，弯弯曲曲的不知道绕了几个弯,小路上
尘土飞扬。东边就是乌鸦嘴的村头了。继续往西方走，南边的西边的
两座越来越近了。
LONG);

	set("outdoors", "shushan");
	set("exits", ([      
		"southwest" : __DIR__"shanlu",
		"east" : __DIR__"exit",
		"north" : __DIR__"jitan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
		if(dir =="north" && me->query("id")=="fei zei" ||("id") == "thief" ||("id") == "zei")
			return 0;
		return ::valid_leave(me, dir);
}
