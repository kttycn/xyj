#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","花园");
	set("long",
HIR"这里种着从血神星移植过来的血噬藤，血噬藤十分妖异，开的花极其艳美
但要是被她的藤茎触到，就必死无疑，不过其藤汁确是极补之物，听说宗
主正用它来练一种极为厉害的武功，所以宗主经常从囚牢里提取犯人来喂
血噬藤，所以虽然只有一株，但早已爬满整个院子了。\n"NOR);
	set("objects", ([
		__DIR__"npc/xueshi": 1,
//           __DIR__"obj/hua2": 2,
	]));
	set("outdoors", "fenghuang");
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"xiaowu",
		"south"  : __DIR__"xiaodao2",
	]));
	set("no_fly",1);
	setup();
}
int valid_leave(object me, string dir)
{
	if (objectp(present("xueshi tengi", environment(me)))) 
	{
		if((int)this_player()->query_condition("teng_poison") < 10 ) {
			this_player()->apply_condition("teng_poison", 30);
			tell_object(me, HIG "你感到一阵巨痛，原来是碰到了血噬藤！\n" NOR );
		}
	}
	return ::valid_leave(me, dir);
}

