#include <ansi.h>
inherit ROOM;

void init();
int do_knock(string);
int do_say(string);
void reset();
void close(object);

void create()
{
	set("short", "С��");
	set("long",
"����һ������ͨͨ��С�ݣ�ǽ��һ��"HIR"�辰"NOR"(penjing)��
�ú�����ʢ������������¹�Ӵ����������ӳ���辰�ϣ����
�����辰��Щ������\n");
	set("objects", ([
		__DIR__"npc/huangxiang": 1,
	]));
	set("exits", ([
		"south": __DIR__"houyuan",
	]));

	set("item_desc", ([
		"penjing" : "���辰�ƺ���ƽ��������������ر�⻬����һ�����ԣ�\n",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_knock","knock");
	add_action("do_say","say");
}

int do_knock(string arg)
{
	object me;
	me=this_player();

	if (!arg || (arg!="penjing" ) )
		return  notify_fail("��Ҫ��ʲô��\n");

	set_temp("marks/pen",1);
	message_vision("$NͻȻ���辰�����˼��£�$N����ѽ��\n",me);
	tell_object(me,"�����������������������������ʲô��û�а�������δ�˵���أ�\n");
	return 1;
}

int do_say(string arg)
{
	object me;
	me = this_player();

	if (!query_temp("marks/pen")) return 0;
	if( !arg || arg=="" ) return 0;

	if (arg == "̤ѩ����Ц�����£����귭����ս����")
	{
		tell_object(me,"���Ȼ֪�����ţ��ͽ����ɡ�\n");
		message("vision", "�辰���ϵ�һ��ǽ�����ƿ���¶����ľ�š�\n", this_player());
		set("exits/down", __DIR__"midao");
		remove_call_out("close");
		call_out("close", 3, this_object());
		return 1;
	}
}

void close(object room)
{
	message("vision","��Ȼһ����Ӱ��������ľ�Ź����ˡ�\n", room);
	room->delete("exits/down");
}
void reset()
{
	::reset();
	delete_temp("marks/pen");
}


