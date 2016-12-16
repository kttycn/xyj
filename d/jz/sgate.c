//Cracked by Roath
#include <ansi.h>
inherit ROOM;
void chen_appearing (object who, object where);

void create()
{
	set ("short", "钓鱼台");
	set ("long", @LONG

以前，这是达官贵人们钓鱼享乐的地方，如今江州城衰落了，
这个地方根本就没人看管了，即使这样，也是少有人来。台
的旁边有个小牌子(paizi)，上面好象写些什么内容。

LONG);
	set("exits", ([
		"north":__DIR__"dingan-3",
	]));
	set("objects", ([
		__DIR__"npc/waiter": 1,
	]));
	set("item_desc", ([
		"paizi": @TEXT
………………………………………………………………………………………………
                    钓鱼：鱼竿每付５两白银
………………………………………………………………………………………………
TEXT
	]) );
	set("outdoors", "jiangzhou");
	setup();
}
void init()
{
	add_action("do_jump", "jump");
	add_action("do_cry", "yell");
}

int valid_leave(object me, string dir)
{
	if (dir == "north"&& me->query("fish") )
		me->delete("fish"); 
	return 1;
}
/*
void say()
{
        object me=this_player();
         write("卖鱼竿的对你说道：嘘~~不要打扰别人钓鱼。\n");
        return 0;
}
*/

int do_jump(string arg)
{
	object me=this_player();
	if( !arg || arg != "river")
	return notify_fail("你要往哪跳？\n");
	me->move(__DIR__"river");
	message_vision(HIC "$N纵身一跳，跳进江中。\n" NOR, me);
	me->add("kee", -40);
	return 1;
}

int do_cry()
{
	object me = this_player();
	object where;


	if( me->query("obstacle/jz") == "done" )
		return notify_fail("你干嚎了两嗓子，眼泪也流不出来。\n");

	if( ! me->query_temp("obstacle/jz_given") )
		return notify_fail("你干嚎了两嗓子，眼泪也流不出来。\n");

	if( present("chen guangrui",environment(me) ))
		return notify_fail("陈光蕊不是在这吗？\n");

	if( random(20) == 6 )
	{       
		where = environment(me);
		message_vision(HIG"只见$N号啕大哭起来，真是如丧考妣。\n"NOR,me);
		tell_room(where,"忽然大海翻腾起来，水面上浮上来一个人....\n");
		me->delete_temp("obstacle/jz_given");
		call_out ("chen_appearing", 1, me, where);
		return 1;
	}
	message_vision(HIG"只见$N号啕大哭起来，但是好象根本没有在乎$N。\n"NOR,me);
	me->start_busy();
	return 1;
}   

void chen_appearing (object who, object where)
{
	object chen = new (__DIR__"npc/chen");

	chen->move(where);
	chen->check (who);
	return ;
}
