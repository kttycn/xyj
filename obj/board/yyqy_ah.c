
inherit BULLE_BOARD;
#include <ansi.h>

void create()
{
	set_name("月影奇缘发展讨论板", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "yyqy_ah");
	set("long",     "这是供巫师和玩家互相交流，共同促进月影奇缘发展的讨论板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLE_BOARD);
}
