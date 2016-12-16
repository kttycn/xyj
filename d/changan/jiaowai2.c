// Room: /d/city/jiaowai8.c
//星星lywin4/29

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小树林");
    set("long", @LONG
这是扬州郊外的一片小树林，落英缤纷，蜂歌蝶舞，朝露夕光，沁人
心脾。呼朋唤友开怀欢乐正其时。周围小树颗颗健美，上有无数的小鸟小
雀在树梢上欢歌，一点也不怕人。这正是个打鸟（da）的好机会。
LONG );
    set("exits", ([
        "east" : __DIR__"nanchengkou",
    ]));
    set("no_clean_up", 0);
    set_temp("wayao1",1);
    setup();
}

void init()
{
        add_action("do_da", "da");
}


int do_da()
{
	object me;
	int i, kar, cps, bb,mm;
	me = this_player();

	if (me->query("combat_exp")>=1000)
		return notify_fail("你已经不能用打鸟来锻炼了。\n");
	if(me->is_busy())
		return notify_fail("你还是等弓装好了箭再打鸟吧！\n");

	if(me->query("kee")<10)
		return notify_fail(HIR"你还是先休息一下吧，射箭也要用力气哟。。\n"NOR);

	me->start_busy(3);
	message_vision("$N拿起儿时玩耍用的小弓小箭，瞄准树上的小雀射去......\n", me);

	message_vision("$N只听树上一阵鸟儿急鸣…\n",me);
	kar = me->query("kar");
        
	if (random(kar)>15) {
		message_vision("$N打到一只"HIW"百灵鸟。\n"NOR, me);
		me->add("combat_exp",10);
		me->add("daoxing",12);
		tell_object(me,"你得到了10点武学经验\n");
		tell_object(me,"你得到了三天道行\n");
		me->receive_damage("kee", 10);
		me->add("potential",4);
		tell_object(me,"你得到了4点潜能\n");
		return 1;
	}
        
	if (random(kar)>10) {
		message_vision("$N打到一只"HIY"金丝雀。\n"NOR, me);
		me->add("combat_exp",8);
		me->add("daoxing",8);
		tell_object(me,"你得到了8点武学经验\n");
		tell_object(me,"你得到了二天道行\n");
		me->receive_damage("kee", 10);
		me->add("potential",3);
		tell_object(me,"你得到了3点潜能\n");
		return 1;
	}
        
	if (random(kar)>8) 
	{
		message_vision("$N打到一只"HIG"鹦鹉。\n"NOR, me);
		me->add("combat_exp",5);
		me->add("daoxing",4);
		tell_object(me,"你得到了5点武学经验\n");
		tell_object(me,"你得到了一天道行\n");
		me->receive_damage("kee", 10);  
		me->add("potential",2);
		tell_object(me,"你得到了2点潜能\n");
		return 1;
	}

	if (random(kar)>5) 
	{
		message_vision("$N打到一只"YEL"麻雀。\n"NOR, me);
		me->add("combat_exp",2);
		me->add("daoxing",2);
		tell_object(me,"你得到了2点武学经验\n");
		tell_object(me,"你得到了六时辰道行\n");
		me->receive_damage("kee", 10);  
		me->add("potential",1);
		tell_object(me,"你得到了1点潜能\n");
		return 1;
	}
	else 
	{
		me->receive_damage("kee", 10);  
		message_vision("$N什么也没打到。\n",me );
	}
	return 1;
}
