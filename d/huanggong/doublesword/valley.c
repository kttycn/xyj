#include <ansi.h>
inherit ROOM;

int do_enter(string arg);

void create()
{
	set("short", "山谷");
	set("long", @LONG
	
此地空谷无人，一片荒凉，削壁环列，宛似身处一口大井之底。
你四下里探望，突然发现一道壁崖(cliff)上似乎有些问题。
你也不知道怎么到这里来的。

LONG
	);

	set("exits", ([
//		"north" : __DIR__"shulin2",
	]));

	set("item_desc", ([ /* sizeof() == 2 */
		"cliff" : "你接着探望，似乎没有其他可攀爬之物,不知道这处洼陷(hole)是什么。\n",
		"hole"  : "你磨试了洼陷(hole)，果然可以攀登(climb)。\n",
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
		return notify_fail("你要爬到哪里去？\n");

	where=environment(who);

	if( !who->query_temp("kill_ziying_dragon")
	|| !who->query_temp("kill_ziying_nvjing") 
	|| !who->query_temp("ask_ziying_laojun") )
	{
		message_vision(HIB"$N试着往壁崖上爬，忽然狂风大作，看来此地非久留之地。\n突然飞出一条神龙！\n"NOR,who);
		dragon = load_object(__DIR__"npc/dragon");
		dragon->move(where);
		return 1;	
	}

	if(!( room = find_object(__DIR__"anshi3")) )
		room = load_object(__DIR__"anshi3");
	if(objectp(room))
	{
		tell_room(environment(who), who->query("name")+"活动了一下手脚。\n" ,who);
		tell_room(environment(who), who->query("name")+"纵身跳了过去，半空中在洼陷中一搭，顺势跃了过去。\n", who);
		tell_object(who,"你活动了一下手脚。\n" ,who);
		tell_object(who,"你纵身跳了过去，半空中在洼陷中一搭，顺势跃了过去。\n", who);
		tell_object(who, HIG"你跃过了壁崖,突然看见山壁上有个黑洞洞的洞口，于是不假思索地钻了进去。
你眼前一暗，竟然来到了一片黑暗之中。\n"NOR);
		who->move(room);
		tell_room( room, HIB"你眼前一闪，"+who->query("name")+"钻了进来。\n"NOR, who);
	}
	return 1;
}

int do_search(string arg)
{
	object me = this_player();

	if(me->is_busy())
		return notify_fail("你现在正忙着呢！\n");

	if(me->query("kee") < 50)
		return notify_fail("你现在太累了，歇会儿吧！\n");

//	if(query("num") <= 0)
//		return notify_fail("这里没什么好找的了！\n");

	message_vision("$N四处寻找着，似乎在追寻着什么。\n",me);
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
		message_vision("忽然狂风大作，看来此地非久留之地。\n",me);
		message_vision(HIB"从壁崖后飞出一条神龙。\n"NOR,me);
		dragon = load_object(__DIR__"npc/dragon");
		dragon->move(where);
//		dragon = new("/d/jz/herb/heshouwu");
//		dragon->move(me);
//		add("num",-1);
		return 1;
	} else {
		message_vision("$N找了半天什么也没找到！\n",me);
		me->start_busy(3);
		return 1;
	}
}