inherit ROOM;
void create()
{
	set("short","[1;36m������");
	set("long",@LONG

	 ���������ŵ���槼�����ʱ��͵�һЩ������ÿ
һ�������㰮�����֡�

LONG);
	set("exits", ([
		"south" : __DIR__"road4",
	]));
	set("objects", ([
		__DIR__"obj/needle1" : 2,
	]) );
	setup();
}

