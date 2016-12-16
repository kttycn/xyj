// moon_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("íìíôÉ½ÁôÑÔ°å", ({ "board" }) );
	set("location", "/d/xuyi/nanmen");
	set("board_id", "xuyi_b");
	set("long",     "íìíôÉ½ÁôÑÔ°å¡£\n" );
	set("capacity", 80);
	setup();
	replace_program(BULLETIN_BOARD);
}

