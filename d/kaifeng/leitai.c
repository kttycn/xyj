// leitai.c 擂台前广场
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","擂台前广场");
	set("long",@long
这里是苏州擂台前面的一个大型广场，有许多人正在擂台上比武，到处
是人山人海，如果你也想试试身手，那么就请跳上擂台(jump leitai)比试比试吧。
long);
	set("exits",([
		"south" : __DIR__"chen2",
	]));
	set("outdoors", "kaifeng");
	setup();
}
 
void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
	object *ob;
	object me;
	int i;
	me = this_player();

	if( !arg || arg=="" || arg !="leitai" ) 
		return notify_fail("你要往哪里跳？\n");

	if (!living(me)) return 0;
	if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 90) {
		message_vision("$N一纵身想越上擂台，结果因为身上负重过多，摔了下来！\n", me);
		me->unconcious();
		return 1;
	}
	ob = deep_inventory(me);
	i = sizeof(ob);
	while (i--)
	if (userp(ob[i]))
	{
		message_vision(HIR"只见一条人影突然闪现,凌空给了$N一掌。\n"NOR, me);
		me->unconcious();
		return notify_fail("");
	}
	if (arg == "leitai")
	{
		if (mapp(this_player()->query_conditions_by_type("poison")) || mapp(this_player()->query_conditions_by_type("hurt")))
			return notify_fail("你身中巨毒，上不去擂台！\n");

		if( (int)me->query_skill("dodge") < 21 )
		{
			message_vision(HIR"$N想要跳上擂台，可惜笨拙的身体刚一离地，身体在空中倾斜，一个狗吃屎摔了下来！\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 20 && (int)me->query_skill("dodge") < 51 )
		{
			message_vision(GRN"$N一纵身，身行在空中晃悠了一下，还好踉跄踉跄地跳上了擂台！\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(HIR"$N一纵身，身行在空中晃悠了一下，还好踉跄踉跄地跳上了擂台！\n" NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 50 && (int)me->query_skill("dodge") < 101 )
		{
			message_vision(HIW"$N双脚一发力，身体在空中一个鹞子大翻身，轻盈的落到了擂台之上！\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(HIW"$N双脚一发力，身体在空中一个鹞子大翻身，轻盈的落到了擂台之上！\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 100 && (int)me->query_skill("dodge") < 151 )
		{
			message_vision(YEL"$N一点地，身行已然拔地而起，在空中一个优美的一个转体，已然落在了擂台之上！\n"NOR, me); 
			me->move(__DIR__"leitai1");
			message_vision(YEL"$N一点地，身行已然拔地而起，在空中一个优美的一个转体，已然落在了擂台之上！\n"NOR, me);
			return 1;
		}
		if( (int)me->query_skill("dodge") > 150 && (int)me->query_skill("dodge") < 200 )
		{
			message_vision(BLU"$N在原地未动，只见身行已然拔地而起，鬼魅般地出现在擂台之上！\n"NOR, me);
			me->move(__DIR__"leitai1");
			return 1;
		}
		if( (int)me->query_skill("dodge") > 200 )
		{
			message_vision(MAG"$N脸上红光闪现，运起独门心法，在空中接连踢出数脚，无声无息地落在擂台之上！\n"NOR, me);
			me->move(__DIR__"leitai1");
			message_vision(MAG"$N脸上红光闪现，运起独门心法，在空中接连踢出数脚，无声无息地落在擂台之上！\n"NOR, me);
			return 1;
		}
		return 1;
	}
	return 1;
}
