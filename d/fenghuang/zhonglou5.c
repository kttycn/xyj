// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "��¥���");
	set("long", @LONG
������������������ϵķ���ֻ��һ�㣬�������ϣ�¥�ݹ�����
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou6",
		"down" : __DIR__"zhonglou4",
	]));
	setup();
	replace_program(ROOM);
}
