
inherit BULLE_BOARD;
#include <ansi.h>

void create()
{
	set_name("��ʦ�����������۰�", ({ "wizwork board", "board" }) );
	set("location", "/d/wiz/workroom");
	set("board_id", "wizwork bbs");
	set("long",     "���ǹ���ʦ���ཻ������¼�����޸ģ���ͬ�ٽ���Ӱ��Ե��չ�����۰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLE_BOARD);
}
