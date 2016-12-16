inherit ROOM;

void create()
{
	set("short", "膳堂");
	set("long", @LONG
这里是凤凰军校的食堂，是学生们用餐的地方。这个食堂很大，
整齐地摆放着一排一排的桌椅。现在桌椅上三三两两的坐着
坐着几个学生，正在用餐。
LONG
	);
	set("exits",([
		"east" : __DIR__"jiaoxue",
	]));
	set("objects", ([
		__DIR__"npc/dashifu" : 1,
		__DIR__"food/jiuhu" : 1,
	]));
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));

	set("no_clean_up", 0);
	setup();
}

int valid_leave()
{
	if((present("hefan", this_player())))
		return notify_fail("吃完盒饭再走吗！\n");
	if((present("jiuhu", this_player())))
		return notify_fail("你不能把酒壶带走！\n");
	return ::valid_leave();
}

