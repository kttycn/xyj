inherit ROOM;
void create()
{
	set("short", "ʿ��ѧУ");
	set("long", @LONG
���Ƿ���ǿ���ľ�У�������Ｏ����14-18�����Ů������ż���ʽ��
������ѧϰ������ѧϰ��һ�з��þ���ѧУ������14-18��ÿ����б�
ҵ���ԣ��ϸ��ɱ�ҵ���������������Ժ�ľ��Ρ�
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"shangjie2",
		"south" : __DIR__"guangchang",
		"east" : __DIR__"zhonglou",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

