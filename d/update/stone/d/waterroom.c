//u/stone/d/jianshenfang.c
//stone 2001/12/20

inherit ROOM;
#include <ansi.h>


void create ()
{
	set ("short","ʯͷ��ϴ�ּ�");
	set ("long", @LONG
	
������ʦʯͷ��ϴ�ּ䣬�������ž������ƵĴ���ʯ����ǽ����
һ�����ĸ߼���ף���ǽ����һ����׵���Ͱ����ǽ��������
һ�������ľ��ӣ��Աߵĸ�����ϴ��ƷһӦ��ȫ��
��������ʯͷ�Ĺ����ҡ�
LONG);
	set("exits", ([ /* sizeof() == 6 */
//		"east" : __DIR__"bookroom",
//		"west" : __DIR__"jianshenfang",
//		"southeast" : __DIR__"waterroom",
		"northwest" : "/d/update/stone/d/stoneroom",
//		"up": "__DIR__guestroom",
//		"east": "u/stone/d/stoneroom",
	]));
	setup();
}