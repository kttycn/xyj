inherit ROOM;
void create()
{
	set("short", "��ѧ¥��¥");
	set("long", @LONG
�����Ƿ�˾�У�Ľ�ѧ��¥��������ѧԱѧϰ�ĵط���
LONG );
	set("exits", ([
		"down" : __DIR__"jiaoxue",
	]));
	set("objects", ([
		__DIR__"npc/master2" : 1,         
	]));
	setup();
	replace_program(ROOM);
}

