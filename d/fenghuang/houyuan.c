#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","��԰");
	set("long",
HIR"�������Ŵ�Ѫ������ֲ������Ѫ���٣�Ѫ����ʮ�����죬���Ļ���������
��Ҫ�Ǳ������پ��������ͱ������ɣ���������֭ȷ�Ǽ���֮���˵��
������������һ�ּ�Ϊ�������书������������������������ȡ������ι
Ѫ���٣�������Ȼֻ��һ�꣬��������������Ժ���ˡ�\n"NOR);
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
			tell_object(me, HIG "��е�һ���ʹ��ԭ����������Ѫ���٣�\n" NOR );
		}
	}
	return ::valid_leave(me, dir);
}

