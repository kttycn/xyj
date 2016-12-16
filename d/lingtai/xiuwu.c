// Room: /d/lingtai/xiuwu.c

inherit ROOM;

void create()
{
	set("short", "修武堂");
	set("long", @LONG
这是一间较大的静室，正对着门的墙上写着一个若大的武字。
房中有四个道士，正手持木杖，仿佛在比划什么。
LONG );
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("objects",([
		__DIR__"npc/guangjing" : 1,      
		__DIR__"npc/guangguan" : 1,
		__DIR__"npc/guangming" : 1,
		__DIR__"npc/guangzhi" : 1,
	]));

	set("no_fight",1);
	set("no_magic",1);
	setup();
}

