
inherit ROOM;

void create()
{
	set("short", "��Ĺʯ��");
	set("long", @LONG
����һƬ�����������µ�ʯͷ��һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"sl0",
		"north" : __DIR__"sl3",
	]));
	setup();
	replace_program(ROOM);
}
