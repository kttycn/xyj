inherit ROOM;
void create()
{
	set("short", "��ҵ��");
	set("long", @LONG
��������ҵ���ϣ����ż�ʵ�ĵ��档�����ǳ����ģ�����
���������˵�ߺ������������һ�������Ľֵ����Ǳ�ʮ�ֳ��֡���
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"west"  : __DIR__"shangjie2",
		"north" : __DIR__"wuqipu",
		"south" : __DIR__"zhahuopu",
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

