#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "ˮ��");
	set("long", @LONG
һ���ܴ��ˮ�أ�����������ɫ��������������ȥ����
�����ܲ���ץ(catch)������
LONG );
	set("objects", ([
		__DIR__"npc/huangji": 1,
	]));
	set("outdoors", "fenghuang");
	set("exits", ([
		"south" : __DIR__"qianyuan",
	]));
	set("no_clean_up", 0);
	set("no_fly",1);
	setup();
}
void init()
{
	add_action("do_catch", "catch");
}
int do_catch(string arg)
{
	object fish, me = this_player();
	if ((string)me->query("family/family_name") != "�����")
	{
		write("�㻹���Ͻ��ܣ�Ҫ�������������˴����ˣ�\n");
		return 1;
	}
	if(!arg || arg != "fish")
		return notify_fail("��Ҫץʲô��\n");
	if( me->is_busy() )
		return notify_fail("����æ���ء�\n");
	if ( (this_player()->query_spi()+this_player()->query_kar()<60) 
	|| query("fish_count")<-2 || random(10) )
		message_vision("ͻȻ����һ������������һβ��ɫ�����㣬����һ�߶�
����$Næ����ȥץ����Ȼ����������ȴһ�������ˡ�\n", me);
	else
	{
		message_vision("̶������һβ��ɫ�����㣬����һ�߶೤��$Næ����ȥץ��һ�Ѱ���
߬�����ġ�\n", me);
		add("fish_count",-1);
		fish = new(__DIR__"obj/fish");
		fish -> move(me);
	}
	me->start_busy(2);
	return 1;
}
