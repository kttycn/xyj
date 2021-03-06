#include <ansi.h>
inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "树林");
	set("long", @LONG
终于走出了树林，你不禁长长的松了口气。和煦的阳光照在你的身上，使你感到
无比的温暖。南边是一座高耸的石山，山上郁郁苍苍，生满树木。山下似乎有个
小洞(cave)。
LONG
	);

	set("exits", ([
		"north" : __DIR__"shulin2",
	]));

	set("item_desc", ([ /* sizeof() == 1 */
		"cave" : "一个很小的洞，说不定可以钻(enter)进去的。\n"
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
		return notify_fail("你要到哪里去？\n");

	where=environment(who);

	if( !who->query_temp("kill_qingsuo_dragon")
	|| !who->query_temp("kill_qingsuo_corpse") 
	|| !who->query_temp("ask_qingsuo_li") )
	{
		message_vision(HIB"$N试着往洞里爬，突然一股寒风吹来，里面钻出一条巨龙！\n"NOR,who);
		dragon = load_object("/d/ourhome/honglou/dreamland/npc/dragon");
		dragon->move(where);
		return 1;	
	}

	if(!( room = find_object("/d/ourhome/honglou/dreamland/clearing")) )
		room = load_object("/d/ourhome/honglou/dreamland/clearing");
	if(objectp(room))
	{
		tell_room(environment(who), who->query("name")+"忽然钻进小洞，不见了。\n", who);
		tell_object(who, HIG"你钻进了小洞，眼前豁然一亮，竟然来到了一片空地中。\n"NOR);
		who->move(room);
		tell_room( room, HIB"你眼前一暗，"+who->query("name")+"从小洞里钻了进来。\n"NOR, who);
	}
	return 1;
}

