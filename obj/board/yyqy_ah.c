
inherit BULLE_BOARD;
#include <ansi.h>

void create()
{
	set_name("��Ӱ��Ե��չ���۰�", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "yyqy_ah");
	set("long",     "���ǹ���ʦ����һ��ཻ������ͬ�ٽ���Ӱ��Ե��չ�����۰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLE_BOARD);
}
