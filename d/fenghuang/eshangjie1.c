inherit ROOM;
void create()
{
	set("short", "��ҵ��");
	set("long", @LONG
��������ҵ���ϣ����ż�ʵ�ĵ��档�����ǳ����ģ��������
���������˵�ߺ������������һ�������Ľֵ��������Ƿ�˴�
���ţ�������һ��ҹ�ܻᣬ�ո۵Ĵ�Ա����������ȥѰ�����֣���
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"eshangjie2",
		"west"  : __DIR__"zhongxin",
		"north" : __DIR__"bank",
		"south" : __DIR__"playroom",
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

