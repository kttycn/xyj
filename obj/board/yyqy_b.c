
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
	set_name("��Ӱ��Ե��չ���۰�", ({ "board" }) );
	set("location", "/d/wiz/entrance");
	set("board_id", "yyqy_b");
	set("long",     "���ǹ���ʦ����һ��ཻ������ͬ�ٽ���Ӱ��Ե��չ�����۰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
