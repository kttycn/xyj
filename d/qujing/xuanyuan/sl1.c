#include <room.h>
#include <ansi.h>
inherit ROOM;
int valid_leave(object me, string dir);


void create()
{
	set("short", "��Ĺʯ��");
	set("long", @LONG
����һƬ�����������µ�ʯͷ��һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __DIR__"sl2",
		"west" : __FILE__,
		"south" : __DIR__"sl0",
		"north" : __FILE__,
	]));
	set("objects", ([
			//					__DIR__"npc/slfox": 1,
	]));
	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

		if (dir == "east"){
			if (objectp(present("slfox", environment(me))))
			{
	message_vision(CYN"������ס$N��ȥ·��˵�������Ѿ��þ�û�������ʵĶ����ˣ��ٺ١�����\n"NOR, me);
	return notify_fail("�������㶨�����߲����ˣ�");
			}
		}
		return ::valid_leave(me, dir);

}
