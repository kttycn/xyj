//u/stone/d/sfloor.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","��¥");
	set ("long", @LONG

˳�Ŵ���ʯ��̨�ף����϶�¥��
�������д���ʿ����Сס�Ŀͷ����������д�Ůʿ����Сס�Ŀͷ���
������һ������ң�������һ��¶�����̨��¥����һ����԰��

¥����ʯͷ�Ĺ����ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"east" : "/d/update/stone/d/guestroom",
		"west" : "/d/update/stone/d/boardroom",
		"north" : "/d/update/stone/d/balcony",
		"south" : "/d/update/stone/d/guestroom1",
		"up": "/d/update/stone/d/garden",
		"down": "/d/update/stone/d/stoneroom",
	]));
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	setup();
}