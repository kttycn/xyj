// wiz_new.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ϵͳ�����", ({ "board" }) );
	set("location", "/d/wiz/wizroom");
	set("board_id", "wiz_new");
	set("long",
		"����һ��ר�Ź���ϵͳ���±䶯������������Ϣ��Сľ�壬ֻ����ʦ�� post��\n" );
	setup();
	set("capacity", 500);
	replace_program(BULLETIN_BOARD);
}
