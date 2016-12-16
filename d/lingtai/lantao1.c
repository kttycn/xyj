// Room: some place in 西牛贺洲
// forrest.c

inherit ROOM;

void create()
{
	set ("short", "松树林");
	set ("long", @LONG

松林之中非常的暗，光线全被如伞如盖的树枝挡住。地下布
满枯枝，每走一步都会发出很翠的响声，。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"lantao",
		"southdown" : __DIR__"forrest",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "fangcun");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}


