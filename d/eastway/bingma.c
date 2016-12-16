// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// create by snowcat.c 4/20/1997
// room: /d/eastway/bingma.c
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", "兵马俑阵");
	set ("long", @LONG

你来到一个巨大的兵马俑阵中，天高云阔，成千上万个栩
栩如生的兵马俑（ｇｕｍｕ）排列成几十路纵队，仿佛正
在从四面八方呼啸而来，你不禁被这个宏伟的场面惊倒。

LONG);

	set("exits", ([
		"west"       : __DIR__"shihuang",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/bingma" : 9,
	]));
	set("outdoors", __DIR__);

	setup();
}

void init()
{
	add_action("do_dig","dig");
}
int do_dig(string arg)
{
	object me=this_player();

	if( (!arg) || !((arg == "gumu") || (arg == "古墓")))
		return notify_fail("你要挖什么？\n");

	me->move("/d/qujing/xuanyuan/entrance.c");
	message_vision(YEL"$N身子往下陷去，等缓过神来你发现你到了另一处所在。\n"NOR, me);
	return 1;
}


