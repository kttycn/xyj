#include <ansi.h>

#include <room.h>
inherit ROOM;

void create()
{
	set("short", HIR"�Ͼ�¯"NOR);
	set("long", @LONG
    
�������̫���Ͼ����������ڡ�����������һֻһ�˶�ߵ�
��ɫ��¯������������ʲô�������ġ�¯���һ����ܣ�Ȼ��
��ȴ���ܲ���һ˿���ȡ�ǽ�Ƿ���һ¯̴�㣬һ˿��������
�������������ơ�

LONG );

	set("exits", ([
	]));

	set("objects", ([ /* sizeof() == 4 */
		__DIR__"npc/taishanglaojun" : 1,
		__DIR__"obj/fire" : 1,
	]));
	set("no_recall",1);
	set("no_bian",1);
	set("no_chuqiao",1);

	setup();
}