
inherit BULLE_BOARD;
#include <ansi.h>

void create()
{
	set_name("巫师工作进度讨论板", ({ "wizwork board", "board" }) );
	set("location", "/d/wiz/workroom");
	set("board_id", "wizwork bbs");
	set("long",     "这是供巫师互相交流、记录程序修改，共同促进月影奇缘发展的讨论板。\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLE_BOARD);
}
