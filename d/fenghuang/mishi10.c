#include <ansi.h>
inherit ROOM;

void init();
int do_open(string);
void reset();
void close(object);

void create()
{
	set("short", "�ܵ�");
	set("long",
"�����ǰ��һ���ú������̳ɵ�̨�ף�һֱ�������죬���ߵ�ǽ�ڶ�
�ǻ����ң�ǽ�ϸ�ʮ��������һյ�͵ƣ�ʹ���ܿ�����Χ,ǽ��һ�ȴ���(door)��
\n");
	set("exits", ([
		"south": __DIR__"mishi8",
	]));

	set("item_desc", ([
		"door" : "����һ���ƾɵĴ���\n",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_open","open");
}
int do_open(string arg)
{
	object me;
	me=this_player();

	if (!arg || (arg!="door" ) )
		return  notify_fail("��Ҫ��ʲô��\n");

	set_temp("lock",1);
	if( query_temp("lock") == 1 && !present("phoenix key", me) )
		return notify_fail("Կ�׶�û�У���ô���ţ�\n");
	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N��Կ�ײ�����ף�ֻ��������ડ�һ���������ˡ�\n", me);
		set("exits/down", __DIR__"mishi11");
		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
    }
}
void close(object room)
{
	message("vision","һ��紵��,���Ź����ˡ�\n", room);
	room->delete("exits/down");
}

void reset()
{
	::reset();
	delete_temp("lock");
}
