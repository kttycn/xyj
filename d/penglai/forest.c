//Room /d/penglai/forest.c

inherit ROOM;

void create()
{
	set("short","树林");
    set("long", @LONG

在这风景如画的蓬莱岛上，四周古树葱葱郁郁，各种奇花异草争奇斗艳
当然也有一些猛兽之类的，在这里你看到了有野兽出没的痕迹。
LONG);
	set("objects",([
		__DIR__"npc/snake" : 1,
	]));
	set("exits",([
		"east" : __DIR__"yaxia",
		"west" : __DIR__"forest1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	object snake;
  
	if( dir=="west")
	{
		if(objectp(snake = present("ju mang",environment(me))))
		return notify_fail(snake->query("name")+"'呼'的一下拦住了你的去路！\n");
	}
	return ::valid_leave(me,dir);
}
