inherit ROOM;
void create()
{
	set("short","ͨ��");
	set("long",@LONG

����ʱ��о���ǰ���������˺ö࣬��ֻС��������Ľ�
�´�����ȥ�������ƽϢ�ˣ��������ܰ��ֻ꣬�����ŵ�
һ�ɺ����ŵ�ζ���������ط�ȴ��ɨ�ĺܸɾ���

LONG);
	set("exits", ([
		"west" : __DIR__"sleeproom",
		"south" : __DIR__"road2",
		"north" : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"npc/fox" : 3,
	]) );
	setup();
}

