// Room: /d/lingtai/yangxin.c

inherit ROOM;

void create()
{
	set("short", "养心堂");
	set("long", @LONG
这是一间静室，正对着门的墙上写着一个若大的静字。
沿着墙壁的蒲团上静静地坐着四个道士，仿佛在闭目
养神。
LONG );
	set("exits", ([
		"east" : __DIR__"wuchang",
	]));
	set("objects",([
		__DIR__"npc/guanghe" : 1,      
		__DIR__"npc/guangji" : 1,
		__DIR__"npc/guangwen" : 1,
		__DIR__"npc/guangxin" : 1,
	]));

	set("no_fight",1);
	set("no_magic",1);
	setup();
}

