#include <ansi.h>
inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
	
�˵ؿչ����ˣ�һƬ���������ڻ��У�������һ�ڴ�֮�ס�
��������̽����ͻȻ����һ������(cliff)���ƺ���Щ���⡣
��Ҳ��֪����ô���������ġ�

LONG
	);

	set("exits", ([
//		"north" : __DIR__"shulin2",
	]));

	set("item_desc", ([ /* sizeof() == 2 */
		"cliff" : "�����̽�����ƺ�û������������֮��,��֪���⴦����(hole)��ʲô��\n",
		"hole"  : "��ĥ��������(hole)����Ȼ�����ʵ�(climb)��\n",
	]));
	set("outdoors", "city");


	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb","pa");
	add_action("do_search","search");
}

int do_climb(string arg)
{
	object dragon, where, room;
	object who = this_player();

	if(!arg  || arg != "hole")
		return notify_fail("��Ҫ��������ȥ��\n");

	where=environment(who);

	if( !who->query_temp("kill_ziying_dragon")
	|| !who->query_temp("kill_ziying_nvjing") 
	|| !who->query_temp("ask_ziying_laojun") )
	{
		message_vision(HIB"$N������������������Ȼ�������������˵طǾ���֮�ء�\nͻȻ�ɳ�һ��������\n"NOR,who);
		dragon = load_object(__DIR__"npc/dragon");
		dragon->move(where);
		return 1;	
	}

	if(!( room = find_object(__DIR__"anshi3")) )
		room = load_object(__DIR__"anshi3");
	if(objectp(room))
	{
		tell_room(environment(who), who->query("name")+"���һ���ֽš�\n" ,who);
		tell_room(environment(who), who->query("name")+"�������˹�ȥ���������������һ�˳��Ծ�˹�ȥ��\n", who);
		tell_object(who,"����һ���ֽš�\n" ,who);
		tell_object(who,"���������˹�ȥ���������������һ�˳��Ծ�˹�ȥ��\n", who);
		tell_object(who, HIG"��Ծ���˱���,ͻȻ����ɽ�����и��ڶ����Ķ��ڣ����ǲ���˼�������˽�ȥ��
����ǰһ������Ȼ������һƬ�ڰ�֮�С�\n"NOR);
		who->move(room);
		tell_room( room, HIB"����ǰһ����"+who->query("name")+"���˽�����\n"NOR, who);
	}
	return 1;
}

int do_search(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("��������æ���أ�\n");

	if(me->query("kee") < 50)
		return notify_fail("������̫���ˣ�Ъ����ɣ�\n");

//	if(query("num") <= 0)
//		return notify_fail("����ûʲô���ҵ��ˣ�\n");

	message_vision("$N�Ĵ�Ѱ���ţ��ƺ���׷Ѱ��ʲô��\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;
}

int finish(object me)
{
	object dragon, where;
	object who = this_player();
	where=environment(who);

	if(random(me->query_kar()) > 15 )
	{
		message_vision("��Ȼ�������������˵طǾ���֮�ء�\n",me);
		message_vision(HIB"�ӱ��º�ɳ�һ��������\n"NOR,me);
		dragon = load_object(__DIR__"npc/dragon");
		dragon->move(where);
//		dragon = new("/d/jz/herb/heshouwu");
//		dragon->move(me);
//		add("num",-1);
		return 1;
	} else {
		message_vision("$N���˰���ʲôҲû�ҵ���\n",me);
		me->start_busy(3);
		return 1;
	}
}