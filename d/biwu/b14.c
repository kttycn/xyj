inherit ROOM;
void create()
{
	set("short", "����¥��");
	set("long", @LONG
������������߲㣬������Ÿ����ȣ������طų���â�������������Ҫ��˳�
��ȥ(yaoche)��
    ����û�г��ڣ���ֻ�ܵȴ���һ���Ӻ��Զ��ͻع㳡��
LONG );
	set("no_sleep_room",1);
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/champion": 1,
	]));

	setup();
}

void init()
{
	add_action("do_dazuo","dazuo");
	add_action("do_dazuo","exercise");
	add_action("do_yao","yaoche");
}

int do_dazuo()
{
	object me;
	me = this_player();
	tell_object(me,"���ﲻ�ܴ�����\n");
	return 1;
}

int do_yao()
{
	object me;

	me = this_player();
	if(!me->query("zhanyi/mengzhu"))
		return notify_fail("��û�г�����Ȩ�ޡ�\n");
	if (!me->query_temp("che"))
		return notify_fail("��ղ�û�г˳������\n");
	me->delete_temp("che");
	message_vision("$N�߳�����¥�����������Ҵ�ææ����ȥ�ˡ�\n",me);
	me->move("/d/city/center");
	message_vision("$N�ֻص��˳�����\n",me);
	return 1;
}

/*
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="down")
{remove_call_out("awayaway");
this_player()->set_temp("for_okok",0);
}return 1;
}*/
