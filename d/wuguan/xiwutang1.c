#include <room.h>

inherit ROOM;

void create()
{
	set("short", "ϰ����");
	set("long", @LONG
��������������ڵ�һ��ϰ���ã�����һ����ͷ�ڽ����书������
�����������ͷѧϰ�����������Ϸ����Ÿ��ң�����д�š��Ե�
���п࣬��Ϊ�����ˡ���
LONG);
	set("exits", ([
		"north" : __DIR__"shibanlu4",
	]));
	set("objects", ([
		__DIR__"npc/zhaowushi" : 1,
	]) );
	setup();
	replace_program(ROOM);
}

