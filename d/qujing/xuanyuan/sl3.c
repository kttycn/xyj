
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
		"west" : __DIR__"sl4",
		"south" : __DIR__"sl0",
		"north" : __DIR__"sl00",
	]));
	setup();
	replace_program(ROOM);
}
