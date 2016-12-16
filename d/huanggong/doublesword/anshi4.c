//Cracked by Roath
inherit ROOM;
#include <room.h>
#include <ansi.h>

void create ()
{
	set ("short", "暗室");
	set ("long", @LONG

这里是一段狭长的暗室，只能一两个人容身。

LONG);
	set("exits", ([ /* sizeof() == 3 */
//  "south" : __DIR__"road1",
	]));
/*	set("objects",([
		"/d/jz/herb/lingzhi" : 2,
	]));
	set("outdoors", "penglai");*/
	setup();
}


void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}

int do_climb(string arg)
{
	object me=this_player();
	
	if( !arg || (arg!="上" && arg!="上面" && arg!="up") )
		return notify_fail("你要爬什么？\n");
	if( me->is_busy())
		return notify_fail("你现在很忙，爬什么呀！\n");
	
	message_vision("$N匍匐前进，小心的爬呀爬。。。\n", me);
	me->start_busy(3);

	if( (int)me->query("kee") < 500 || (int)me->query("sen") < 500) {
		call_out("faila", 3, me);
		return 1;
	}

	if( (int)me->query_skill("dodge",1)+(int)me->query_skill("unarmed",1) <=200 ){
		call_out("faila", 3, me);
		return 1;
	}

	if( random((int)me->query_kar()) <= 5){
		call_out("faila", 3, me);
		return 1;
	}
 
	call_out("success", 3, me);
	return 1;
}
int success(object me)
{
	message_vision("$N越爬越高，渐渐隐入黑暗之中。。。\n", me);
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N慢慢的爬了上去。黑暗中$N摸到一个机纽，$N按了下机纽。\n", me);
	message_vision(HIC"只听喀嚓一声! 一道暗门滑开，$N走了出来。\n"NOR,me);
	me->move("/d/huanggong/doublesword/houdian");
	return 1;
}
int faila(object me)
{
	tell_object(me, "你小心翼翼的往上爬了一点，觉得头晕眼花，就赶紧爬了回来.\n");
	tell_room(environment(me), me->name()+"你身子发虚，一头栽了下来，哎呀！\n", ({me, me}));
	me->unconcious();
	
	return 1;
}
