inherit ROOM;

void create()
{
	set("short", "��Ĺʯ��");
	set("long", @LONG
����һƬ�����������µ�ʯͷ��һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __DIR__"sl1",
		"west" : __DIR__"sl",
		"south" : __DIR__"sl1",
		"north" : __DIR__"sl00",
	]));
	setup();
	replace_program(ROOM);
}
