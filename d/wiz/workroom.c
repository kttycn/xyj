//By waiwai@mszj  2000/11/17

#include <ansi.h>

inherit ROOM;

void create ()
{
	set ("short", "管理员工作室");
	set ("long", @LONG

这里是系统管理员（天神）为各级管理员工作学习而修建的工作室。
满目的清新的花草充满了整个的房间。

LONG);
	set("exits", 
	([ //sizeof() == 3
		"kz" : "/d/city/kezhan",
		"north" : __DIR__"wizroom",
                 "up" : "/d/update/stone/d/stoneroom",
	]));

	set("no_death", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_magic", 1);
	set("no_time", 1);

	set("no_clean_up", 0);
	set("valid_startroom", 1);
	call_other( "/obj/board/work_bbs", "???" );

	setup();
}

void init()
{
	string str;
	object me = this_player();
	switch(me->query("gender")) 
	{
		case "女性":
			switch( wizhood(me) ) {
				case "(admin)":
					str = "女神";
					break;
				case "(arch)":
					str = "仙子";
					break;
				case "(wizard)":
					str = "大魔女";
					break;
				case "(apprentice)":
					str = "魔女";
					break;
				case "(immortal)":
					str = "小魔女";
					break;
				case "(elder)":
					str = "小精灵";
					break;
            }
            break;
		case "男性":
			switch( wizhood(me) ) {
				case "(admin)":
					str = "天神";
					break;
				case "(arch)":
					str = "龙神";
					break;
				case "(wizard)":
					str = "仙人";
					break;
				case "(apprentice)":
					str = "巫师";
					break;
				case "(immortal)":
					str = "魔法师";
					break;
				case "(elder)":
					str = "小精灵";
					break;
			}
			break;
	}
	tell_room( environment(me), CYN"主控电脑说道：请注意，【"+str+"】" + me->query("title") 
	+ " " + me->query("name") + "(" + capitalize(me->query("id")) + ")" + " 来到了工作室！！！\n"NOR);
}


