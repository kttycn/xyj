#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "前院");
	set("long", @LONG
你走进大院，迎面是一个假山水池，池中立着一块巨大无比的翡翠，显然是
凤凰星进贡来的宝物。水池的两旁种满了花草。西边一条长廊走道通往后院，
有几个家丁正在忙碌。
LONG );
	set("outdoors", "fenghuang");
	set("exits", ([
		"north" : __DIR__"shuichi",
		"south" : __DIR__"gate",
		"east" : __DIR__"huayuan1",
		"west" : __DIR__"huayuan2",
	]));
	set("objects", ([
		__DIR__"npc/zhangmen" : 1,
		__DIR__"npc/jia" : 3,
	]));
	set("no_fly",1);
	setup();
	replace_program(ROOM);
}

