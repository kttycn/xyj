// 古墓入口
inherit ROOM;
void create()
{
	set("short","入口");
	set("long",@LONG

　　此时的路虽然还是很窄，但是前面毕竟有了一丝亮光，
让你澎湃的心境暂时的安定下来，你小心翼翼的向前摸索
着，忽然路上一个东西拌了你一下，你仔细一看，原来是
带着鲜血的人头。

LONG);
	set("exits", ([
		"out" : __DIR__"entrance",
		"north" : __DIR__"road2",
	]));
	setup();
}

