#include <ansi.h>

inherit "/d/dntg/laojunlu/laojunlu.c";

void create()
{
	::create();
	set("short", HBMAG HIG" ¿² ¹¬ "NOR);
	set("objects", ([ /* sizeof() == 4 */
		__DIR__"obj/fire" : 1,
	]));
	set("no_recall",1);
	set("no_bian",1);
	set("no_chuqiao",1);

	setup();
}