//standroom.c used by weiqi...others may hate this format:D
//xueshan4.c

inherit ROOM;

void create ()
{
	set ("short", "茫茫雪峰");
	set ("long", @LONG

北风呼啸，飞雪茫茫，四面望去均是绵延不尽的雪峰。天地之间
似已毫无生迹，除了雪还是雪。在这里你好像可以挖(dig)到什么。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"south" : __DIR__"snowmaze9",
		"north" : __DIR__"xueshan5",
	]));
	
	set("objects", 
	([ //sizeof() == 1
	]));
	set("num",10);
	set("outdoors", "xueshan");

	setup();
}

void init()
{
	add_action("do_dig","dig");
	add_action("do_dig","wa");
}

int do_dig(string arg)
{
	object me = this_player();
	object weapon;

	if(!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你空着手怎么挖？\n");
	if((weapon->query("skill_type") != "sword") 
	&& (weapon->query("skill_type") != "blade"))
		return notify_fail("你得找个刀或剑之类的才能挖呀！\n");
	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

	if(query("num") <= 0)
		return notify_fail("这里面的东西已经被别人挖光了！\n");
	if(me->query("kee") < 50)
		return notify_fail("你现在手脚酸软，什么也做不了！\n");

	message_vision("$N操起"+weapon->query("name")+"在雪地里挖了起来！\n",me);
	me->start_busy(3);
	me->receive_damage("kee",50);
	call_out("finish",3,me);
	return 1;
}

int finish(object me)
{
	object renshen;
	if(random(me->query_kar()) > 20)
	{
		message_vision("$N一阵惊喜，发现了一个人参！\n",me);
		message_vision("慢慢的，$N把人参整个拿了出来！\n",me);
		renshen = new("/d/jz/herb/renshen");
		renshen->move(me);
		add("num",-1);
		return 1;
	}
	else{
		message_vision("结果除了一个坑，$N什么也没挖到！\n",me);
		return 1;
	}
}

void reset()
{
    set("num",10);
    ::reset();
}
