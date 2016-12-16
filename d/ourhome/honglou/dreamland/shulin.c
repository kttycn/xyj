#include <ansi.h>
inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "����");
	set("long", @LONG
�����߳������֣��㲻�����������˿������������������������ϣ�ʹ��е�
�ޱȵ���ů���ϱ���һ�����ʵ�ʯɽ��ɽ�������Բԣ�������ľ��ɽ���ƺ��и�
С��(cave)��
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin2",
	]));

	set("item_desc", ([ /* sizeof() == 1 */
		"cave" : "һ����С�Ķ���˵����������(enter)��ȥ�ġ�\n"
	]));

	setup();
}

void init()
{
	add_action("do_enter", "zuan");
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object dragon, where, room;
	object who = this_player();

	if(!arg || arg != "cave")
		return notify_fail("��Ҫ������ȥ��\n");

	where=environment(who);

	if( !who->query_temp("kill_qingsuo_dragon")
	|| !who->query_temp("kill_qingsuo_corpse") 
	|| !who->query_temp("ask_qingsuo_li") )
	{
		message_vision(HIB"$N��������������ͻȻһ�ɺ��紵�����������һ��������\n"NOR,who);
		dragon = load_object("/d/ourhome/honglou/dreamland/npc/dragon");
		dragon->move(where);
		return 1;	
	}

	if(!( room = find_object("/d/ourhome/honglou/dreamland/clearing")) )
		room = load_object("/d/ourhome/honglou/dreamland/clearing");
	if(objectp(room))
	{
		tell_room(environment(who), who->query("name")+"��Ȼ���С���������ˡ�\n", who);
		tell_object(who, HIG"�������С������ǰ��Ȼһ������Ȼ������һƬ�յ��С�\n"NOR);
		who->move(room);
		tell_room( room, HIB"����ǰһ����"+who->query("name")+"��С�������˽�����\n"NOR, who);
	}
	return 1;
}

