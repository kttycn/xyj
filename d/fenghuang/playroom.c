// Room: /d/game/playroom.c 
inherit ROOM; 
void create() 
{ 
	set("short", "凤凰游乐场");
	set("long", @LONG
这里是筹码兑换处...要在游乐场内玩必须要有筹码喔...这里有一位 
服务亲切的小姐可以为你兑换筹码喔... 
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

