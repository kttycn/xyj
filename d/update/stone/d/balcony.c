//u/stone/d/balcony.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","¶����̨");
	set ("long", @LONG
	
һ��������̨��վ�������㲻������ĺ��˼����������˸���
������ʱ�е�������ˬ��һ������ȥ��һ��Ƭ����Ĳݵ�ӳ����
����
�����Ƕ�¥��
LONG);
	set("exits", ([ /* sizeof() == 6 */
		"south" : "/d/update/stone/d/sfloor",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	setup();
}