inherit ROOM;
void create()
{
	set("short", "��ѧ¥");
	set("long", @LONG
�����Ƿ�˾�У�Ľ�ѧ��¥��������ѧԱѧϰ�ĵط���
LONG );
	set("exits", ([
		"west" : __DIR__"shitang",
		"east" : __DIR__"guangchang",
		"up" : __DIR__"jiaoxue1",
	]));
	set("objects", ([
		__DIR__"npc/master1" : 1,
	]));
	setup();
	replace_program(ROOM);
}
