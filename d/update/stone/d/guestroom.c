//u/stone/d/guestroom.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","��ʿ�ͷ�");
	set ("long", @LONG

����һ�������д����˵ĺ����ͻ���װ�εø����ûʣ�������
�ִ���Ϣ�������þߣ�һӦ�߱�����˵�ǰ���ͳ�ı�׼���ġ�

�����Ƕ�¥��
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : "u/stone/d/guestroom",
		"west" : "/d/update/stone/d/sfloor",
//		"north" : "u/stone/balcony",
//		"southwest" : "u/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"down": "u/stone/d/stoneroom",
	]));
	setup();
}