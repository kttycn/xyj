//  妖神之争 １。０
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "江中");
	set ("long", @LONG

江中水流湍急，向下流去，你被水一冲，顿时觉得头昏脑晕，
根本不知道自己身在何处。只见前方模模糊糊仿佛是一座庙
宇。
LONG);
	setup();
}

void init()        
{
	object me=this_player();
	remove_call_out("go");
	call_out("go",3,me);
}
void go(object me)
{
	if( random(20) < 10 )
	{
		message_vision(HIG"只见一个大浪打来，$N顺水向下淌去。\n"NOR,me);
		me->add("kee",-80);
		me->move("/d/sea/maze0");
		tell_object(me,"你发现自己来到了另一个地方。\n");
	}
	else {
		message_vision(HIG"$N在水中与水搏击着。\n"NOR,me);
		message_vision(HIG"$N在水中与水搏击着。\n"NOR,me);
		me->move("/d/jz/riverside");
		tell_object(me,GRN"你抹了一把汗....爬上了岸边。\n"NOR);
		me->add("kee",-40);
	}
}
        
