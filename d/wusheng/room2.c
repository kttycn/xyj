// changan wusheng
// room1.c

inherit ROOM;

void create()
{
	set ("short", "����");
	set ("long", @LONG

��ʥ�ŵ�����Ϣ�ĵط������˵��䣬������ʥ�ŵ�����Ϣ�ĵط�
Ҳ�ܽ������ߴ�������¯�԰飬�¹�������������̡�ԡ
�̡���������ȫ�����һ���һ��������ָ�ӣ�ʮ��ʵ�á�
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west": __DIR__"room1",
	]));
//	set("objects", ([
//		"/clone/money/thousand-cash": 3
//	]));

	set("no_clean_up", 0);
	set("sleep_room",1);
	set("if_bed",1);

	setup();
	replace_program(ROOM);
}

