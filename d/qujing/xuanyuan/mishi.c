inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG

������һ������ɧ���ķ��ӣ��谵�ĵƹ����˵���Ѫһ�㣬
���㲻������������ϡ���Կ���һЩ����ķ�㣬�������
���仹�Ǿ������˹��ٵġ�

LONG);
	set("exits", ([
		"north": __DIR__"dadian",
		"south":__DIR__"mishi2",
	]));
	set("objects", ([
		__DIR__"npc/zhangmen" : 1,
	]) );
	setup();
}

void init()
{
	object *inv;
	int i;

	inv = all_inventory();
	for(i=sizeof(inv)-1; i>=0; i--)
	{
		if(!interactive(inv[i]))
			if (!living(inv[i])) destruct(inv[i]);
	}

	add_action("do_none","get");
	add_action("do_none","ji");
	add_action("do_none","steal");
	add_action("do_none","put");
	add_action("do_none","drop");
}

int do_none()
{
	object zm=present("zhang men");
	if( zm )
	{
	message_vision("$N��$nҡ��ҡͷ��\n",zm,this_player());
	return 1;
	}
	return 1;
}
int valid_leave(object me, string dir)
{
	if (!(me->query_temp("can_in")) && dir == "south" &&
	(string)me->query("family/family_name") != "��ԯ��Ĺ" )
		return notify_fail("ֻ��槼������Ų���ȥ�ǡ�\n");
	return ::valid_leave(me, dir);
}
