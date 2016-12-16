//standroom.c used by weiqi...others may hate this format:D
//xueshan4.c

inherit ROOM;

void create ()
{
	set ("short", "ããѩ��");
	set ("long", @LONG

�����Х����ѩãã��������ȥ�������Ӳ�����ѩ�塣���֮��
���Ѻ�������������ѩ����ѩ������������������(dig)��ʲô��
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"snowmaze9",
		"north" : __DIR__"xueshan5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));
	set("num",10);
	set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_dig","dig");
	add_action("do_dig","wa");
}

int do_dig(string arg)
{
	object me = this_player();
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("���������ô�ڣ�\n");
	if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("����Ҹ�����֮��Ĳ�����ѽ��\n");
	if(me->is_busy())
		return notify_fail("����æ���أ�\n");

	if(query("num") <= 0)
		return notify_fail("������Ķ����Ѿ��������ڹ��ˣ�\n");
	if(me->query("kee") < 50)
		return notify_fail("�������ֽ�����ʲôҲ�����ˣ�\n");

	message_vision("$N����"+weapon->query("name")+"��ѩ��������������\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;
}

int finish(object me)
{
	object renshen;
	if(random(me->query_kar()) > 20)
	{
		message_vision("$Nһ��ϲ��������һ���˲Σ�\n",me);
		message_vision("�����ģ�$N���˲��������˳�����\n",me);
		renshen = new("/d/jz/herb/renshen");
		renshen->move(me);
		add("num",-1);
		return 1;
	}
	else{
		message_vision("�������һ���ӣ�$NʲôҲû�ڵ���\n",me);
		return 1;
	}
}

void reset()
{
    set("num",10);
    ::reset();
}
