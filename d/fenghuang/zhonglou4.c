// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "��¥�Ĳ�");
	set("long", @LONG
���������������ϣ�˿�첻¶��
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou5",
		"down" : __DIR__"zhonglou3",
	]));
	setup();
	replace_program(ROOM);
}
