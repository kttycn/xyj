#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ǰԺ");
	set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ���������һ��޴��ޱȵ���䣬��Ȼ��
����ǽ������ı��ˮ�ص����������˻��ݡ�����һ�������ߵ�ͨ����Ժ��
�м����Ҷ�����æµ��
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"shuichi",
		"south" : __DIR__"gate",
		"east" : __DIR__"huayuan1",
		"west" : __DIR__"huayuan2",
	]));
	set("objects", ([
		__DIR__"npc/zhangmen" : 1,
		__DIR__"npc/jia" : 3,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

