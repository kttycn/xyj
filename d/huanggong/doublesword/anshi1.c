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
	
	if( !arg || (arg!="下" && arg!="下面" && arg!="down") )
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
	message_vision("$N越爬越低，渐渐隐入黑暗之中。。。\n", me);
	me->receive_damage("kee", 400);
	me->receive_damage("sen", 400);
	message_vision("$N慢慢的爬了下来。黑暗中$N摸到一个机纽，$N按了下机纽。\n", me);
	message_vision(YEL"只听轰隆隆几声! 一道山壁向两边滑开，$N走了出来。\n"NOR,me);
	message_vision(YEL"又听“呯”的一声，山壁合了起来，回复原状。\n"NOR,me);
	me->move(__DIR__"valley");
	return 1;
}
int faila(object me)
{
	tell_object(me, "你小心翼翼的往下爬了一点，觉得头晕眼花，就赶紧爬了回来.\n");
	tell_room(environment(me), me->name()+"脸色苍白，大汗淋漓地从下面爬了回来，脚一踏到地，一头栽倒在地，哎呀！\n", ({me, me}));
	me->unconcious();
	
	return 1;
}
