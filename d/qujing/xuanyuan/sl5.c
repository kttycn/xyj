
inherit ROOM;

void create()
{
	set("short", "��Ĺʯ��");
	set("long", @LONG
����һƬ�����������µ�ʯͷ��һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __DIR__"sl6",
		"west" : __FILE__,
		"south" : __DIR__"sl0",
		"north" : __FILE__,
	]));
	setup();
	replace_program(ROOM);
}
