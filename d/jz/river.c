//  ����֮�� ������
//  happ@YSZZ 2000.4.2
// /d/jz/river.c

inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short", "����");
	set ("long", @LONG

����ˮ���ļ���������ȥ���㱻ˮһ�壬��ʱ����ͷ�����Σ�
������֪���Լ����ںδ���ֻ��ǰ��ģģ�����·���һ����
�
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
		message_vision(HIG"ֻ��һ�����˴�����$N˳ˮ������ȥ��\n"NOR,me);
		me->add("kee",-80);
		me->move("/d/sea/maze0");
		tell_object(me,"�㷢���Լ���������һ���ط���\n");
	}
	else {
		message_vision(HIG"$N��ˮ����ˮ�����š�\n"NOR,me);
		message_vision(HIG"$N��ˮ����ˮ�����š�\n"NOR,me);
		me->move("/d/jz/riverside");
		tell_object(me,GRN"��Ĩ��һ�Ѻ�....�����˰��ߡ�\n"NOR);
		me->add("kee",-40);
	}
}
        
