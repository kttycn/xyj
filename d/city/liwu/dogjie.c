// Room: /d/liwu/dogjie.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ��������뻶�ֽ����������Խֵ��ϳ���
��ϲ�õ����ա��������������֣��Ǿ��ǻ��ֽ��ˣ�������һ����̫
��ĳ�������ݣ�����԰���ĳ�����������
LONG
	);
	set("outdoors", "city");

	set("exits", ([
		"northwest" : __DIR__"happyjie",
              "east" : __DIR__"dog_room",
	]));

	set("objects", ([
		__DIR__"npc/shaofu" : 1,
		__DIR__"npc/jentleman" : 1,
		__DIR__"npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}

