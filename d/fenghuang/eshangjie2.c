inherit ROOM;
void create()
{
	set("short", "��ҵ��");
	set("long", @LONG
��������ҵ���ϣ����ż�ʵ�ĵ��档����������������˵�ߺ��
����������һ�������Ľֵ��������������䵱�У������Ƿ����
������ľƵ꣬�������ÿͶ�������ȥ��Ϣ����
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"rukou",
		"west"  : __DIR__"eshangjie1",
		"north" : __DIR__"dangpu",
		"south" : __DIR__"sleep-room",
	]));
	set("objects", ([
//          "/d/city/npc/?" : 1,
//          "/d/city/npc/?"    : 2,
	]));
//      set("no_clean_up", 0);
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}


