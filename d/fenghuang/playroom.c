// Room: /d/game/playroom.c 
inherit ROOM; 
void create() 
{ 
	set("short", "������ֳ�");
	set("long", @LONG
�����ǳ���һ���...Ҫ�����ֳ��������Ҫ�г����...������һλ 
�������е�С�����Ϊ��һ������... 
LONG    );
	set("no_clean_up", 0);
	set("light", 1);
	set("exits", ([ /* sizeof() == 2 */
		"up" : __DIR__"diceroom",
		"north" : __DIR__"eshangjie1",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chiplady" : 1,
	]));
	setup();
	replace_program(ROOM);
}

