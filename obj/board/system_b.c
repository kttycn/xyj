// wizard_b.c

inherit BULLETIN_BOARD;

void create()
{
	set_name("ϵͳ�����", ({ "board" }) );
	set("location", "/d/wiz/system");
	set("board_id", "system_b");
	set("long",
		"����һ��ר�Ź���ϵͳ��Ѷ�İ��ӣ�ֻ����ʦ�� post��\n" );
	setup();
	set("capacity", 150);
	replace_program(BULLETIN_BOARD);
}
