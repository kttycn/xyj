//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set ("short", HIW"�����޽�֮��"NOR);
	set ("long", @LONG
�ſڴ��������������������צ�����˲���������
������Ǵ�˵�еİ����޽���ڣ�ֻ������д�ţ�
[1;31m      ��     ��[2;37;0m
[1;31m      ��     ��[2;37;0m
[1;31m      ��     ��[2;37;0m
[1;31m      ��     ��[2;37;0m
LONG);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"lu1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/egui" : 2,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "north") {
		if (objectp(present("xiuluo egui", environment(me))))
			return notify_fail("���޶��ֽе�����������������𣿾������Ұ����޽磡\n");
	}

	return ::valid_leave(me, dir);
}
