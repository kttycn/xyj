#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name("  ʯ��  ", ({ "shibi" }) );
	set("location", "/d/shushan/tianshi");
	set("board_id", "shibi_b");
	set("long", "һ�鱻ĥƽ�˵�ʯ�ڣ���д��"HIC"������"NOR"��
������������������������������������������������������������������������\n");
	setup();
	set("capacity", 80);
	replace_program(BULLETIN_BOARD);
}

