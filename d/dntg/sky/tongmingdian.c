//sgzl

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "ͨ����");
	set("long", @LONG
    
�빬�Ĵ��������ǰ���죬�߲���Զ�������������ˡ�
�������������Կ���������ΰ�ĵ��ţ��ʹ�˵�����
����������ǡ�
LONG );


	set("exits", ([
		"north"   : __DIR__"bishagong",
		"south"   : __DIR__"caihongqiao2",
		"west"   : __DIR__"baoguangdian",
		"down"   : "/d/niulang/yinhe",
		"east"   : __DIR__"lingxudian",
	]));

	set("objects", ([
		__DIR__"npc/youshengzhenjun" : 1,
	]));

	setup();
}
