// wsboard.c ��ʥ�����԰�

inherit BULLETIN_BOARD;

void create()
{
        set_name("��ʥ�����԰�", ({ "board" }) );
        set("location", "/d/wusheng/room3.c");
        set("board_id", "wsboard");
        set("long",     "��ʥ�����԰塣�ڵ��Ӷ�ϲ�����������Խ������顣\n" );
        setup();
        set("capacity", 80);
        replace_program(BULLETIN_BOARD);
}

