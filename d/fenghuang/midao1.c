inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一条用汉白玉铺成的台阶，一直向下延伸，两边的墙壁都
是花岗岩，墙上隔十来步就有一盏油灯，使你能看清周围。
LONG );
	set("exits", ([
		"northup" : __DIR__"midao",
		"southdown": __DIR__"midao2",
	]));
//	set("no_clean_up", 0);
	  setup();
}

