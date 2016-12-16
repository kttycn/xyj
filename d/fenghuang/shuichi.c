#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "水池");
	set("long", @LONG
一个很大的水池，里面有许多金色的鲤鱼在游来游去，你
试试能不能抓(catch)几条。
LONG );
	set("objects", ([
		__DIR__"npc/huangji": 1,
	]));
	set("outdoors", "fenghuang");
	set("exits", ([
		"south" : __DIR__"qianyuan",
	]));
	set("no_clean_up", 0);
	set("no_fly",1);
	setup();
}
void init()
{
	add_action("do_catch", "catch");
}
int do_catch(string arg)
{
	object fish, me = this_player();
	if ((string)me->query("family/family_name") != "凤凰星")
	{
		write("你还不赶紧跑，要不被宗主府的人逮到了！\n");
		return 1;
	}
	if(!arg || arg != "fish")
		return notify_fail("你要抓什么？\n");
	if( me->is_busy() )
		return notify_fail("你正忙着呢。\n");
	if ( (this_player()->query_spi()+this_player()->query_kar()<60) 
	|| query("fish_count")<-2 || random(10) )
		message_vision("突然泼喇一声，池中跳起一尾金色大鲤鱼，足有一尺多
长，$N忙伸手去抓，虽然碰到了鱼身，却一滑滑脱了。\n", me);
	else
	{
		message_vision("潭中跳起一尾金色大鲤鱼，足有一尺多长，$N忙伸手去抓，一把把它
攥在手心。\n", me);
		add("fish_count",-1);
		fish = new(__DIR__"obj/fish");
		fish -> move(me);
	}
	me->start_busy(2);
	return 1;
}
