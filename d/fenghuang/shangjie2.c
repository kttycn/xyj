inherit ROOM;
void create()
{
	set("short", "��ҵ��");
	set("long", @LONG
�����Ƿ�˳ǵ���ҵ�֡��������Ƿ�������ĳ��У�����ʮ�ַ�������
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"east"  : __DIR__"shangjie1",
		"north" : __DIR__"jqrdian",
		"down" : __DIR__"shanghui",
		"south" : __DIR__"xiaoxue",
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

