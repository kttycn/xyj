#include <room.h>

inherit ROOM;

void create()
{
	set("short", "习武堂");
	set("long", @LONG
　　这里是武馆内的一个习武堂，堂内一个教头在教着武功，几个
新手正在向教头学习功夫，堂子正上方挂着个匾，上面写着“吃得
苦中苦，放为人上人”。
LONG);
	set("exits", ([
		"north" : __DIR__"shibanlu4",
	]));
	set("objects", ([
		__DIR__"npc/zhaowushi" : 1,
	]) );
	setup();
	replace_program(ROOM);
}

