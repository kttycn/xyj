#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "����¥");
	set("long", @LONG
����һ�������������˼�ʮ������ֵ�¥������ʮ�Ĳ�֮�ߡ�
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"northdown" : "/d/city/center",
		"up":__DIR__"b2",
	]));
		set("objects", ([
			__DIR__"npc/qinqiong": 1,
		]));
	setup();
}

void init()
{
	add_action("do_dazuo","dazuo");
	add_action("do_dazuo","exercise");
	if(userp(this_player()) && (!this_player()->query_temp("for_okok")))
	{
		call_out("awayaway",900);
		message_vision("��ֻ��һ���ӵ�ʱ�����������и��֡����۳ɹ����һ���Ӻ��㽫�Զ����ͻس���ʮ�ֽ�ͷ��\n",this_player());
		this_player()->set_temp("for_okok",1);
	}
}

int awayaway()
{
	object me;
	me= this_player();
	message_vision("�ѹ���һ���ӵ�ʱ�䣬$N�����͵��㳡���롣\n",me);
	me->move("/d/city/center");
	message_vision("$N������ͻȻ�����ڹ㳡���롣\n",me);
	this_player()->set_temp("for_okok",0);
	return 1;
}

int do_dazuo()
{
	object me;
	me = this_player();
	tell_object(me,"���ﲻ�ܴ�����\n");
	return 1;
}
int valid_leave(object me, string dir)
{
	object ob;
	if( userp(me) && dir=="up" && ob=present("qin qiong", this_object()))
		return notify_fail("����Ӳ������\n");
	return 1;
}
