// Room: /d/welcome/newbie1
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "入世之路");
	set ("long", @LONG
月影奇缘的入世之路是一条混沌之路，这路通向的是诡异的“人、
神、鬼”三界，为了你能在今后的江湖路上过得一帆风顺，建议你先
看一遍[1;33m help newbie[2;37;0m，在那里面详细的解说了一个新手在泥潭中的生
存之道。要入世，看它是必不可少。
LONG);

	set("no_magic", 1);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"newbie2",
	]));
	set("no_beg", 1);
	set("pingan", 1);
	set("no_fight", 1);

	setup();
	replace_program(ROOM);
}
