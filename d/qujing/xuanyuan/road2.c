// ��Ĺ���
inherit ROOM;
void create()
{
	set("short","���");
	set("long",@LONG

����ʱ��о���ǰ���������˺ö࣬��ֻС��������Ľ�
�´�����ȥ�������ƽϢ�ˣ��������ܰ��ֻ꣬�����ŵ�
һ�ɺ����ŵ�ζ���������ط�ȴ��ɨ�ĺܸɾ���

LONG);
	set("exits", ([
		"out" : __DIR__"entrance",
		"north" : __DIR__"road3",
	]));
	set("objects", ([
		__DIR__"npc/fox" : 3,
	]) );
	setup();
}

