//2001.5.22
//by yxm
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set ("short", HIW"������"NOR);
	set ("long", @LONG

[1;31m**************************************[2;37;0m
[1;31m**               ������             **[2;37;0m
[1;31m**************************************[2;37;0m

LONG);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"diyu6",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/18gui" : 1,
	]));
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "down") {
		if (objectp(present("gui", environment(me))))
			return notify_fail("��ֽе�����������������𣿾�������ʮ�˲������\n");
	}

	return ::valid_leave(me, dir);
}
