//u/stone/d/garden.c
//stone 2001/12/21

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","��¥");
	set ("long", @LONG

����һ����԰���������ָ����滨��ݣ����ĵĻ��㡢��ݵ���
�¡�һȺȺ���۷䡢�����ڻ����з��裬��һ��������

¥����ʯͷ�Ķ�¥��
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"down": "/d/update/stone/d/sfloor",
	]));
	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
//	set("freeze",1);
	set("no_time", 1);
	setup();
}