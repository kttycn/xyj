// Room: /d/wiz/newsroom at fei
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
	set ("short", MAG"��Ӱ��Ե"NOR"���ŷ�������");
	set ("long", @LONG

������������Ӱ��Ե�����ŷ������ģ���ʲô���Ŷ����������﷢
����Ȼ��ϵͳ�Զ�֪ͨ������ҡ�

LONG);

	set("no_fight", 1);
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"wizroom",
	]));
	set("no_clean_up", 1);
	setup();
	replace_program(ROOM);
}
