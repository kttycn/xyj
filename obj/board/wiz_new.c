// wiz_new.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("系统公告板", ({ "board" }) );
	set("location", "/d/wiz/wizroom");
	set("board_id", "wiz_new");
	set("long",
		"这是一个专门公告系统最新变动及各种修正信息的小木板，只有巫师能 post。\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
