// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "��¥����");
	set("long", @LONG
������������������ϵķ���ֻ��һ�㣬�������ϣ�¥�ݹ��������Ͽ�
����������һ�ڴ��ӡ�
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"zhonglou5",
		"up" : __DIR__"zhonglou7",
	]));
	setup();
	replace_program(ROOM);
}
