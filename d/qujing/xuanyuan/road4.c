inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG

������������Ƕ��������ˣ���������ŵ�ɧ��ζ�������谵
��ɫ�⣬��������ʲôҲû�У�ż���м�ֻ�������˹�����·
���⿪ʼ�ֲ��ˣ����е��Ի��ˡ�

LONG);
	set("exits", ([
		"east" : __DIR__"nei1",
		"south" : __DIR__"road3",
		"west" : __DIR__"dan",
		"north" : __DIR__"road5",
	]));
	set("objects", ([
		__DIR__"npc/fox" : 1,
	]) );
	setup();
}

