inherit ROOM;

void create()
{
	set("short", "��˴�Ƶ�");
	set("long", @LONG
�����������Զ��ķ�˴�Ƶ��ˣ�����߸ߵĽ����Ѿ�����
���ĳǵı�־�Խ��������������Ըо�����Υ�ļҵĸо�����
Ϊ��˳�������ľƵ꣬�κη�����շѶ��Ǿ��˵ģ�����������
�������ſ�վһ��Ҳ��е�������ⲻ�ٵġ�
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
//      set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "¥�ϱ�������ͳ�׷���ÿҹʮ���ƽ�\n",
	]));
	set("objects", ([
		__DIR__"npc/fuwusheng" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"eshangjie2",
		"up"   : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("����������ò����ס�������Ԥ�����䣡\n");

	return ::valid_leave(me, dir);
}

