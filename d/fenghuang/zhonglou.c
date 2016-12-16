inherit ROOM;

void create()
{
	set("short", "钟楼一层");
	set("long", @LONG
这是一座砖木结构的宝塔，塔高七层，塔身作八角形，飞檐
翘翎，檐角上挂满了一串串小铜铃，随风叮叮作响。塔身墙上镂
空雕绘着无数凤凰城先贤们的事迹。一个个形态维肖，看来出自
名匠之手。
LONG );
	set("exits", ([
		"west" : __DIR__"xiaoxue",
		"up" : __DIR__"zhonglou2",
	]));
	set("objects",([
		__DIR__"npc/bing" : 2,
	]));
//      set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

