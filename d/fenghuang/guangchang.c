inherit ROOM;
void create()
{
	set("short", "�ٳ�");
	set("long", @LONG
���Ƿ���Ǿ�У�Ĳٳ����������кܶ�ѧ���ڽ̹ٵĶ�����ѵ����������
ѧ�������ᣬ�����ǽ�ѧ¥��
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"xiaoxue",
		"south" : __DIR__"wuchang",
		"west" : __DIR__"jiaoxue",
		"east" : __DIR__"shushe",
	]));
	set("objects", ([
		"/d/fenghuang/npc/kaoguan" : 1,
		"/d/fenghuang/npc/zhuren" : 1,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

