//Cracked by Roath
//anshi.c
//#include <room.h>
//STONE
inherit ROOM;

int can_enter=1;

void create ()
{
	set ("short", "雪山之巅");
	set ("long", @LONG

只见山野银霜遍地，树梢披挂雪花，素净纯美得使人屏息。这
雪白的世界更似和天空连接起来，再无分彼我。寒风呼呼中，
层峦叠翠，群山起伏，历历在目。踏足之处，脚下松软的白雪
咯咯作响，头上则雪花飘舞，林海雪原，教人滤俗忘忧。空气
中隐隐约约，似有异香扑鼻，不知从何而来。 
LONG);

	set("no_clean_up", 1);
	set("exits", 
	([ //sizeof() == 4
		"west" : __DIR__"xueshan5",
	]));
	set("objects", 
	([ //sizeof() == 1
		__DIR__"npc/snake1" : 1,
	]));

//	can_enter=1;

	setup();
}


void init()
{
	add_action("do_dig", "dig");
	add_action("do_dig", "wa");

	if( query("started") != 1 )
	{
		set("started", 1);
		call_out("generate", 259200+random(1080) );//75小时
//		call_out("generate", 180+random(60) );//75小时
	}
}

void generate()
{
	remove_call_out("generate");
	set("available", 1);
}

void reset_enter()
{
	can_enter=1;
}

int do_dig(string arg)
{
	object shen, weapon;
	object me = this_player();
	int kee;
	   if( (!arg) || (arg != "xue shen" && arg != "xueshen" && arg != "snowshen" && arg !="雪参") )
     	return notify_fail("你要挖什么？\n");
	        if (objectp(present("xue she", environment(me))))
        return notify_fail("千年雪蛇「嗖」的一声，钻了过来，对你怒目而视，红信长吐，好不凶恶。\n");
		if(!objectp(weapon = me->query_temp("weapon")))
	return notify_fail("你空着手怎么挖？\n");
		if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("你得找个刀或剑之类的才能挖呀！\n");
	if(me->query("kee") < 50)
		return notify_fail("你现在手脚酸软，什么也做不了！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	notify_fail("你操起"+weapon->query("name")+"用力在雪地里挖了起来，但什么也没挖着。\n");
		me->start_busy(3);
/*	message_vision("$N操起"+weapon->query("name")+"在雪地里挖了起来！\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;*/
	
	kee=me->query("kee");
	if(kee<110) return 0;
	kee-=100;
	me->set("kee",kee);

	kee=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(kee<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		if(random(2))
			shen = new(__DIR__"obj/snowginseng");
		else
			shen = new(__DIR__"obj/snowginseng");
		shen -> move(this_object());
		message_vision("突然你看到雪穴中一株雪白硕大的参，轻轻掘了起来，顿时一股浓郁的参香飘散在空中。
你不禁深深地吸了一口气。\n", me);

		remove_call_out("generate");
		call_out("generate", 144000+random(1080) );//40小时
//		call_out("generate", 180+random(60) );//75小时

		return 1;
	}
	return 0;
}

	
int clean_up()
{
	return 0;
}
