// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
	set("short", "��¥����");
	set("long", @LONG
�Ѿ���ϰ�����������Ĺ����¿�����������ǽ��֮�ϻ����˱�
����ֻ����ã����Կ����ˡ�
LONG
	);
	set("exits", ([ 
		"up" : __DIR__"zhonglou3",
		"down" : __DIR__"zhonglou",
	]));
	setup();
	replace_program(ROOM);
}
