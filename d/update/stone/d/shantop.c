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

见惯了一望无际的雪原，巍峨雄伟的冰山，突然间碧波万顷，浩
瀚壮阔的水面展现在面前，你顿时觉得一股柔情蜜意涌上心头。
山，湖，草，鸟，仿佛是到了另一个世界。你试着到处挖了挖
(wa)。 
LONG);

	set("no_clean_up", 1);
	can_enter=1;

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
	object me, shen, weapon;
	int sen;
	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你空着手怎么挖？\n");
	if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("你得找个刀或剑之类的才能挖呀！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");
	notify_fail("你什么也没摸着。\n");
//	if(query("num") <= 0)
//		return notify_fail("这里面的东西已经被别人挖光了！\n");
	if(me->query("kee") < 50)
		return notify_fail("你现在手脚酸软，什么也做不了！\n");
	
	sen=me->query("sen");
	if(sen<110) return 0;
	sen-=100;
	me->set("sen",sen);

	sen=(me->query("combat_exp")+me->query("daoxing"))/2;
	if(sen<50000) return 0;

	if( query("available") == 1 )
	{
		set("available", 0);
		if(random(2))
			guo = new(__DIR__"obj/snowginseng");
		else
			guo = new(__DIR__"obj/snowginseng");
		shen -> move(this_object());
		message_vision("突然你看到雪穴中一株硕大饱满的人参，顿时一股浓郁的参香飘散在空中。
		你深深吸了一口气。\n", me);

		remove_call_out("generate");
		call_out("generate", 259200+random(1080) );

		return 1;
	}
	return 0;
}

/*	message_vision("$N操起"+weapon->query("name")+"在雪地里挖了起来！\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;*/

	
int clean_up()
{
	return 0;
}
