//u/stone/d/jianshenfang.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","ʯͷ�Ľ���");
	set ("long", @LONG
	
������ʦʯͷ�Ľ��������ķ����з���һ̨̨����ʽ������
������е���������ź��ĵ�̺��������ϵķ��Ź⣬��ǽ����
��һ̨��ʽ����ˮ����ʯͷ��ʱ����������
������ʯͷ�Ĺ����ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"northeast" : __DIR__"chufang",
//		"up": "__DIR__guestroom",
		"east": "/d/update/stone/d/stoneroom",
	]));
	setup();
}