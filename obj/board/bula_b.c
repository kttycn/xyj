inherit BULLETIN_BOARD;

void create()
{
	set_name("û������", ({"board"}) );
set("location", "/u/bula/workroom");
set("board_id", "bula_b");
set("capacity", 100);
set("long", "����˵Ҳ��˵��
������������������������������������������������������������\n");
        setup();
        replace_program(BULLETIN_BOARD);
}

