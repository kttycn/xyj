#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("  石壁  ", ({ "shibi" }) );
	set("location", "/d/shushan/tianshi");
	set("board_id", "shibi_b");
	set("long", "一块被磨平了的石壁，上写“"HIC"西蜀剑派"NOR"”
————————————————————————————————————\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

