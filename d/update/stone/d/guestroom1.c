//u/stone/d/guestroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","Ůʿ�ͷ�");
	set ("long", @LONG

����һ�������д����˵ĺ����ͻ���װ�εø����ûʣ�������
�ִ���Ϣ�������þߣ�һӦ�߱�����˵�ǰ���ͳ�ı�׼���ġ�

�����Ƕ�¥��
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : "u/stone/d/guestroom",
//		"west" : "u/stone/d/sfloor",
		"north" : "/d/update/stone/d/sfloor",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"down": "u/stone/d/stoneroom",
	]));
	setup();
}