//����ɽ�ɡ�mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","�ؾ���");
	set ("long", @LONG

��ɽ���ɵĲؾ��󣬶�����һ����ܣ�������Щ�����书����顣
��������Ϸ��Ź����ڹ��ͷ�������顣������һ������ϸ�о���
LONG);

	set("exits", ([ 
		"west" : __DIR__"eastway4",
	]));
	set("objects", ([
		__DIR__"obj/yijing"    : 1,
	]));
	setup();
}

void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	object me=this_player();
	if ((arg != "shujia" && arg != "���") || !arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if (me->is_busy()) return notify_fail("��æ���أ�\n");
	if (me->query("family/master_name") == "��������")
	{
		message_vision(HIM"$N��һ����ʹ�â����,������һ���ط���\n"NOR, me);
		me->move(__DIR__"midao");
	}
	else 
	{
		tell_object (me,"������ܸ���?\n");
	}
	return 1;
}








