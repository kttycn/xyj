// Room: /d/liwu/lipinroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"������Ʒ��"NOR);
	set("long", @LONG
����һ���������С���ӣ���Ӵ���������ȥ����������������ʵƣ�
�����������ա��ſ���һ���Ͱ����������ڷ�������ú�����˶�Ц�����գ�
:�Ͽ��ȥ��һ���ɣ���ask man about �����    
LONG);

	set("exits", ([
		"southwest"      :__DIR__"happyjie",
	]));

	set("objects", ([
		__DIR__"npc/xmas_men" : 1,
		__DIR__"npc/happyboy" : 1,
		__DIR__"npc/happygirl" : 1,

	]));


	setup();
	replace_program(ROOM);
}

