#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "桃花迷阵");
	set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往南是一片桃
花林，往北远方遥遥听见轰轰隆隆的水声,似乎有个瀑布。
LONG );
	set("exits", ([
		"south" : __DIR__"tao_in",
		"north" : __DIR__"pubu",
	]));
	set("outdoors", "pansidong");
	set("no_clean_up", 0);
	setup();
}
