// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 

inherit BULLETIN_BOARD;

void create()
{
	set_name("��ԯ��", ({ "board" }) );
	set("location", "/d/qujing/xuanyuan/dadian.c");
	set("board_id", "xy_b");
	set("long", "����һ��ľ�壬��¼�Ź�Ĺ��һ�С�\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
