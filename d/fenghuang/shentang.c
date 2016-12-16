#include <room.h>

inherit ROOM;
void create()
{
	set("short", "大圣堂");
	set("long", @LONG
这里是大圣堂的正殿，正面是凤凰女神的雕像。殿两侧供奉着凤凰星
的古代先圣，武人到此，都放下武器，毕恭毕敬地瞻仰朝拜。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");

	set("objects", ([
		__DIR__"obj/shen" : 1
	]));

	set("exits", ([
		"north" : __DIR__"zhongxin",
	]));
	setup();
	replace_program(ROOM);
}


