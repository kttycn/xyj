//u/stone/d/cookroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","����");
	set ("long", @LONG
	
������ʦʯͷ��������������ִ���һӦ��ȫ����������������
������Ĳ��ȡ����ġ�С�ԡ��տ�����ǽ����һ�����ĵ���䣬
��icebox)����ǽ��������һ̨�Զ��ۻ�����automat)��
��������ʯͷ�Ĺ����ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
		"southwest" : "/d/update/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	set("objects", ([ /* sizeof() == 2 */
//		__DIR__"npc/robot1" : 1,
		"/d/update/stone/obj/automat" : 1,
        ]));
	setup();
}