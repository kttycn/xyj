// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("����ɽ���԰�", ({ "board" }) );
	set("location", "/d/xuyi/nanmen");
	set("board_id", "xuyi_b");
	set("long",     "����ɽ���԰塣\n" );
	set("capacity", 80);
	setup();
	replace_program(BULLETIN_BOARD);
}

